#ifndef UTILS_QRC_OUTPUT_HPP
#define UTILS_QRC_OUTPUT_HPP

#include <list>
#include <string>
namespace Utils {
auto getListAllQRC() -> std::list<std::string>;
auto getFormattedListOfAllQRC() -> std::string;
} // namespace Utils

#endif // !UTILS_QRC_OUTPUT_HPP
