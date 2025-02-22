// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: elasticcdc.proto

#include "elasticcdc.pb.h"
#include "elasticcdc.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace elasticcdc {

static const char* ElasticcdcService_method_names[] = {
  "/elasticcdc.ElasticcdcService/SayHello",
  "/elasticcdc.ElasticcdcService/SayHelloAgain",
  "/elasticcdc.ElasticcdcService/ImageClassify",
  "/elasticcdc.ElasticcdcService/IsPreempted",
};

std::unique_ptr< ElasticcdcService::Stub> ElasticcdcService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ElasticcdcService::Stub> stub(new ElasticcdcService::Stub(channel, options));
  return stub;
}

ElasticcdcService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SayHello_(ElasticcdcService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SayHelloAgain_(ElasticcdcService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ImageClassify_(ElasticcdcService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_IsPreempted_(ElasticcdcService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ElasticcdcService::Stub::SayHello(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::elasticcdc::ElasticcdcReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void ElasticcdcService::Stub::async::SayHello(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void ElasticcdcService::Stub::async::SayHello(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::elasticcdc::ElasticcdcReply, ::elasticcdc::ElasticcdcRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SayHello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ElasticcdcService::Stub::SayHelloAgain(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::elasticcdc::ElasticcdcReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SayHelloAgain_, context, request, response);
}

void ElasticcdcService::Stub::async::SayHelloAgain(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHelloAgain_, context, request, response, std::move(f));
}

void ElasticcdcService::Stub::async::SayHelloAgain(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHelloAgain_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::PrepareAsyncSayHelloAgainRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::elasticcdc::ElasticcdcReply, ::elasticcdc::ElasticcdcRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SayHelloAgain_, context, request);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::AsyncSayHelloAgainRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloAgainRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ElasticcdcService::Stub::ImageClassify(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::elasticcdc::ElasticcdcReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ImageClassify_, context, request, response);
}

void ElasticcdcService::Stub::async::ImageClassify(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ImageClassify_, context, request, response, std::move(f));
}

void ElasticcdcService::Stub::async::ImageClassify(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ImageClassify_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::PrepareAsyncImageClassifyRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::elasticcdc::ElasticcdcReply, ::elasticcdc::ElasticcdcRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ImageClassify_, context, request);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::AsyncImageClassifyRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncImageClassifyRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ElasticcdcService::Stub::IsPreempted(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::elasticcdc::ElasticcdcReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_IsPreempted_, context, request, response);
}

void ElasticcdcService::Stub::async::IsPreempted(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_IsPreempted_, context, request, response, std::move(f));
}

void ElasticcdcService::Stub::async::IsPreempted(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_IsPreempted_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::PrepareAsyncIsPreemptedRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::elasticcdc::ElasticcdcReply, ::elasticcdc::ElasticcdcRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_IsPreempted_, context, request);
}

::grpc::ClientAsyncResponseReader< ::elasticcdc::ElasticcdcReply>* ElasticcdcService::Stub::AsyncIsPreemptedRaw(::grpc::ClientContext* context, const ::elasticcdc::ElasticcdcRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncIsPreemptedRaw(context, request, cq);
  result->StartCall();
  return result;
}

ElasticcdcService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ElasticcdcService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ElasticcdcService::Service, ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ElasticcdcService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::elasticcdc::ElasticcdcRequest* req,
             ::elasticcdc::ElasticcdcReply* resp) {
               return service->SayHello(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ElasticcdcService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ElasticcdcService::Service, ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ElasticcdcService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::elasticcdc::ElasticcdcRequest* req,
             ::elasticcdc::ElasticcdcReply* resp) {
               return service->SayHelloAgain(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ElasticcdcService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ElasticcdcService::Service, ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ElasticcdcService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::elasticcdc::ElasticcdcRequest* req,
             ::elasticcdc::ElasticcdcReply* resp) {
               return service->ImageClassify(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ElasticcdcService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ElasticcdcService::Service, ::elasticcdc::ElasticcdcRequest, ::elasticcdc::ElasticcdcReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ElasticcdcService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::elasticcdc::ElasticcdcRequest* req,
             ::elasticcdc::ElasticcdcReply* resp) {
               return service->IsPreempted(ctx, req, resp);
             }, this)));
}

ElasticcdcService::Service::~Service() {
}

::grpc::Status ElasticcdcService::Service::SayHello(::grpc::ServerContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ElasticcdcService::Service::SayHelloAgain(::grpc::ServerContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ElasticcdcService::Service::ImageClassify(::grpc::ServerContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ElasticcdcService::Service::IsPreempted(::grpc::ServerContext* context, const ::elasticcdc::ElasticcdcRequest* request, ::elasticcdc::ElasticcdcReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace elasticcdc

