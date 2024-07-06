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

  std::string ImageClassify(const std::string& file_name) {
    ElasticcdcRequest request;
    request.set_image_classify_request_info(file_name);
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

 private:
  std::unique_ptr<ElasticcdcService::Stub> stub_;
};
int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  const std::string target_str = "localhost:50051";
  ElasticcdcClient client(grpc::CreateChannel(
                          target_str, grpc::InsecureChannelCredentials()));
    const std::string file_name("world");
    std::string reply = client.ImageClassify(file_name);
    std::cout << "rpc client recieve: " << reply << std::endl; 
  return 0;
}



