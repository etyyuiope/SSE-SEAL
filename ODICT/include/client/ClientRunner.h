#ifndef CLIENT_RUNNER_H
#define CLIENT_RUNNER_H

#include <client/Client.h>
#include <proto/seal.grpc.pb.h>
#include <proto/seal.pb.h>

#include <string>

class ClientRunner : public Seal::Service {
private:
    std::unique_ptr<Seal::Stub> stub_;

    std::unique_ptr<SEAL::Client> client;

    void setup(const std::string &address);

public:
    ClientRunner(const std::string& address);

    /**
     * @brief JUST A WRAPPER FOR SEAL-CLIENT.
     */
    ClientRunner(const int& bucket_size, const int& block_number,
        const int& block_size, const int& odict_size,
        const size_t& max_size, const unsigned int& alpha,
        const unsigned int& x, std::string_view password,
        std::string_view connection_info, const char * address = "127.0.0.1:4567");

    ~ClientRunner();
};

#endif