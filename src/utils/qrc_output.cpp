#include "qrc_output.hpp"
#include <QDirIterator>
#include <algorithm>
#include <sstream>

auto Utils::getListAllQRC() -> std::list<std::string> {
  QDirIterator it(":", QDirIterator::Subdirectories);
  std::list<std::string> list;

  while (it.hasNext()) {
    list.push_back(it.next().toStdString());
  }

  return list;
}

auto Utils::getFormattedListOfAllQRC() -> std::string {
  auto list = getListAllQRC();
  std::stringstream output;

  output << "Resources list:";

  std::for_each(list.begin(), list.end(), [&](std::string x) {
    output << std::format("{:>{}}", x, std::ranges::count(x, '/')) << std::endl;
  });

  return output.str();
}
