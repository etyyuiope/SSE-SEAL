#ifndef UTILS_H_
#define UTILS_H_

#ifndef MAX
#define MAX(a, b) ((a > b) ? a : b)
#endif

#include <algorithm>
#include <iostream>
#include <string>

#include <Objects.h>
#include <OramInterface.h>

/**
 * @brief The template will provide us with a function equivalent to
 *        instanceof in Java.
 */
template <typename Base, typename T>
inline bool instanceof (const T*)
{
    return std::is_base_of<Base, T>::value;
}

template <typename Dst, typename Src>
inline Dst* transform(Src* data)
{
    return static_cast<Dst*>(static_cast<void*>(data));
}

OramInterface::Operation
deduct_operation(OramAccessOp op);

void copy(ODict::Node* const dst, const ODict::Node* const src);

int get_height(const ODict::Node* const node);

std::string
random_string(const int& length, std::string_view secret_key);

std::vector<std::string>
split(const std::string& input, const std::string& regex);

/**
 * @brief A secure PRP.
 */
std::vector<unsigned int> pseudo_random_permutation(const size_t& value_size,std::string_view secret_key);

std::pair<unsigned int, unsigned int> get_bits(const unsigned int &base, const unsigned int& number, const unsigned int& alpha);

#endif