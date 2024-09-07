### 安装gRPC

https://grpc.io/docs/languages/cpp/quickstart/

```bash
# 安装依赖TRITON_ENABLE_CC_GRPC
export MY_INSTALL_DIR=$HOME/.local
mkdir -p $MY_INSTALL_DIR
export PATH="$MY_INSTALL_DIR/bin:$PATH"
sudo apt install -y build-essential autoconf libtool pkg-config
git clone --recurse-submodules -b v1.64.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc

# 编译安装
cd grpc
mkdir -p cmake/build
pushd cmake/build
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
      ../..
make -j 4
make install
popd

# 编译测试程序
cd examples/cpp/helloworld
mkdir -p cmake/build
pushd cmake/build
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j 4

# 运行测试程序
./greeter_server
./greeter_client
```

### 安装dockerTRITON_ENABLE_CC_GRPC

```bash
curl -fsSL http://mirrors.aliyun.com/docker-ce/linux/ubuntu/gpg | apt-key add -
add-apt-repository "deb [arch=amd64] http://mirrors.aliyun.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
apt update
apt install -y docker-ce docker-ce-cli containerd.io
systemctl start docker
```

### 安装triton server

https://github.com/triton-inference-server/server

```bash
# Step 1: Create the example model repository
git clone -b r24.06 https://github.com/triton-inference-server/server.git
cd server/docs/examples
./fetch_models.sh

# Step 2: Launch triton from the NGC Triton container
docker run --gpus=1 --rm --net=host -v ${PWD}/model_repository:/models nvcr.io/nvidia/tritonserver:24.06-py3 tritonserver --model-repository=/models
docker run  --rm --net=host -v ${PWD}/model_repository:/models nvcr.io/nvidia/tritonserver:24.06-py3 tritonserver --model-repository=/models

# Step 3: Sending an Inference Request
# In a separate console, launch the image_client example from the NGC Triton SDK container
docker run -it --rm --net=host nvcr.io/nvidia/tritonserver:24.06-py3-sdk
/workspace/install/bin/image_client -m densenet_onnx -c 3 -s INCEPTION /workspace/images/mug.jpg

# Inference should return the following
Image '/workspace/images/mug.jpg':
    15.346230 (504) = COFFEE MUG
    13.224326 (968) = CUP
    10.422965 (505) = COFFEEPOT
    
# batch request
/workspace/install/bin/image_client -m inception_graphdef -c 3 -s INCEPTION -b 3 /workspace/images

Request 0, batch size 3
Image '/workspace/images/mug.jpg':
    0.754047 (505) = COFFEE MUG
    0.157065 (969) = CUP
    0.002878 (968) = ESPRESSO
Image '/workspace/images/mug.jpg':
    0.754047 (505) = COFFEE MUG
    0.157065 (969) = CUP
    0.002878 (968) = ESPRESSO
Image '/workspace/images/mug.jpg':
    0.754047 (505) = COFFEE MUG
    0.157065 (969) = CUP
    0.002878 (968) = ESPRESSO
```

### 安装triton client

```bash
cmake -DCMAKE_INSTALL_PREFIX=`pwd`/install -DTRITON_ENABLE_CC_HTTP=ON -DTRITON_ENABLE_CC_GRPC=ON -DTRITON_ENABLE_PERF_ANALYZER=OFF -DTRITON_ENABLE_PERF_ANALYZER_C_API=OFF -DTRITON_ENABLE_PERF_ANALYZER_TFS=OFF -DTRITON_ENABLE_PERF_ANALYZER_TS=OFF -DTRITON_ENABLE_PYTHON_HTTP=OFF -DTRITON_ENABLE_PYTHON_GRPC=OFF -DTRITON_ENABLE_JAVA_HTTP=OFF -DTRITON_ENABLE_GPU=OFF -DTRITON_ENABLE_EXAMPLES=ON -DTRITON_ENABLE_TESTS=OFF ..
make cc-clients -j 4

./image_client -m densenet_onnx -c 3 -s INCEPTION ~/server/qa/images/mug.jpg 

# HTTP
cmake -DCMAKE_INSTALL_PREFIX=`pwd`/install -DTRITON_ENABLE_CC_HTTP=ON -DTRITON_ENABLE_CC_GRPC=OFF -DTRITON_ENABLE_PERF_ANALYZER=OFF -DTRITON_ENABLE_PERF_ANALYZER_C_API=OFF -DTRITON_ENABLE_PERF_ANALYZER_TFS=OFF -DTRITON_ENABLE_PERF_ANALYZER_TS=OFF -DTRITON_ENABLE_PYTHON_HTTP=OFF -DTRITON_ENABLE_PYTHON_GRPC=OFF -DTRITON_ENABLE_JAVA_HTTP=OFF -DTRITON_ENABLE_GPU=OFF -DTRITON_ENABLE_EXAMPLES=ON -DTRITON_ENABLE_TESTS=OFF ..
make cc-clients -j 4

./install/bin/image_client -m densenet_onnx -c 1 -s INCEPTION -i http ~/server/qa/images/mug.jpg 
```

### 端口被占

```bash
sudo lsof -i :8001
sudo kill -9 <PID>
```

### Could NOT find OpenSSL, try to set the path to OpenSSL root folder in the
system variable OPENSSL_ROOT_DIR (missing: OPENSSL_CRYPTO_LIBRARY) (found version "3.0.13")

```bash
sudo apt-get install libssl-dev
```

### Could NOT find ZLIB (missing: ZLIB_LIBRARY ZLIB_INCLUDE_DIR)

```bash
sudo apt-get install zlib1g-dev
```

### By not providing "FindOpenCV.cmake" in CMAKE_MODULE_PATH this project has asked CMake to find a package configuration file provided by "OpenCV", but CMake did not find one.

```bash
sudo apt-get install libopencv-dev
```

### 找不到rapidjson

```bash
git clone https://github.com/Tencent/rapidjson.git
cd rapidjson/
mkdir build
cd build
cmake ..
make 
sudo make install
```

### 编译

```bash
# 第一次编译 需要编译grpc相关库
cmake -DCMAKE_INSTALL_PREFIX=`pwd`/install -DTRITON_ENABLE_CC_HTTP=ON -DTRITON_ENABLE_CC_GRPC=ON -DTRITON_ENABLE_PERF_ANALYZER=OFF -DTRITON_ENABLE_PERF_ANALYZER_C_API=OFF -DTRITON_ENABLE_PERF_ANALYZER_TFS=OFF -DTRITON_ENABLE_PERF_ANALYZER_TS=OFF -DTRITON_ENABLE_PYTHON_HTTP=OFF -DTRITON_ENABLE_PYTHON_GRPC=OFF -DTRITON_ENABLE_JAVA_HTTP=OFF -DTRITON_ENABLE_GPU=OFF -DTRITON_ENABLE_EXAMPLES=ON -DTRITON_ENABLE_TESTS=OFF ..

# 之后编译
cmake -DCMAKE_INSTALL_PREFIX=`pwd`/install -DTRITON_ENABLE_CC_HTTP=ON -DTRITON_ENABLE_CC_GRPC=OFF -DTRITON_ENABLE_PERF_ANALYZER=OFF -DTRITON_ENABLE_PERF_ANALYZER_C_API=OFF -DTRITON_ENABLE_PERF_ANALYZER_TFS=OFF -DTRITON_ENABLE_PERF_ANALYZER_TS=OFF -DTRITON_ENABLE_PYTHON_HTTP=OFF -DTRITON_ENABLE_PYTHON_GRPC=OFF -DTRITON_ENABLE_JAVA_HTTP=OFF -DTRITON_ENABLE_GPU=OFF -DTRITON_ENABLE_EXAMPLES=ON -DTRITON_ENABLE_TESTS=OFF ..
make cc-clients -j 4

# 运行backend
./install/bin/image_client

# 运行frontend
./greet_client
```