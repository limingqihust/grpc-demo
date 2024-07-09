/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <stdlib.h>
#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/elasticcdc.grpc.pb.h"
#else
#include "elasticcdc.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using elasticcdc::ElasticcdcRequest;
using elasticcdc::ElasticcdcReply;
using elasticcdc::ElasticcdcService;

class ElasticcdcClient {
 public:
  ElasticcdcClient(std::shared_ptr<Channel> channel)
    : stub_(ElasticcdcService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user) {
    // Data we are sending to the server.
    ElasticcdcRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    ElasticcdcReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->SayHello(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }
  std::string SayHelloAgain(const std::string& user) {
    // Follows the same pattern as SayHello.
    ElasticcdcRequest request;
    request.set_name(user);
    ElasticcdcReply reply;
    ClientContext context;

    // Here we can use the stub's newly available method we just added.
    Status status = stub_->SayHelloAgain(&context, request, &reply);
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

  std::string ImageClassify(const std::string& file_name, int id) {
    ElasticcdcRequest request;
    request.set_image_classify_request_info(file_name);
    // request.set_model_name("inception_graphdef");
    request.set_model_name("densenet_onnx");
    request.set_scale("INCEPTION");
    request.set_filename(file_name);
    request.set_id(id);
    ElasticcdcReply reply;
    ClientContext context;

    // Here we can use the stub's newly available method we just added.
    Status status = stub_->ImageClassify(&context, request, &reply);
    if (status.ok()) {
      return reply.image_classify_reply_info();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

  bool IsPreempted() {
    ElasticcdcRequest request;
    ElasticcdcReply reply;
    ClientContext context;
    Status status = stub_->IsPreempted(&context, request, &reply);
    if (status.ok()) {
      return false;   // not preempted
    } else {
      return true;    // is preempted
    }
  }

 private:
  std::unique_ptr<ElasticcdcService::Stub> stub_;
};


const std::vector<std::string> res = {"15.349563:504:COFFEE MUG",
                                "13.135877:817:SPORTS CAR", 
                                "16.531471:23:VULTURE"};

const std::vector<std::string> filenames = {"/home/lmq/server/qa/images/mug.jpg",
                                            "/home/lmq/server/qa/images/car.jpg",
                                            "/home/lmq/server/qa/images/vulture.jpeg"};
int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  const std::string target_str = "localhost:50051";
  ElasticcdcClient client(grpc::CreateChannel(
                          target_str, grpc::InsecureChannelCredentials()));
  std::thread thds[10];
  for (int i = 0; i < 10; i++) {
    thds[i] = std::thread([&client, i](){
      for (int j = 0; j < 10; j++) {
        if (client.IsPreempted()) {
          std::cout << "rpc server is preempted" << std::endl;
        } else {
          std::cout << "rpc server is not preempted" << std::endl;
        }
        int index = rand() % filenames.size();
        int id = i * 10 + j;
        std::cout << "send request: " << id << std::endl;
        std::string reply = client.ImageClassify(filenames[index], id);
        if (reply != res[index]) {
          std::cout << "request: " << filenames[index] << ", recieve reply: " << reply << std::endl;
          exit(-1);
        } else {
          std::cout << "request: " << id << " is correct" << std::endl;
        }
      }
    });
  }

  for (int i = 0; i < 10; i++) {
    thds[i].join();
  }
}


// int main(int argc, char** argv) {
//   // Instantiate the client. It requires a channel, out of which the actual RPCs
//   // are created. This channel models a connection to an endpoint specified by
//   // the argument "--target=" which is the only expected argument.
//   // We indicate that the channel isn't authenticated (use of
//   // InsecureChannelCredentials()).
//   const std::string target_str = "localhost:50051";
//   ElasticcdcClient client(grpc::CreateChannel(
//                           target_str, grpc::InsecureChannelCredentials()));
//   if (client.IsPreempted()) {
//     std::cout << "rpc server is preempted" << std::endl;
//   } else {
//     std::cout << "rpc server is not preempted" << std::endl;
//   }

//   std::string reply = client.ImageClassify("/home/lmq/server/qa/images", 0);
//   std::cout << "reply: " << reply << std::endl;  
// }



