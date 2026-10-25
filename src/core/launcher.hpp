#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP

#include <QApplication>
#include <cstdint>

class Launcher {
private:
  std::unique_ptr<QApplication> app;

public:
  Launcher() = delete;
  Launcher(std::int32_t argc, char **argv);
  auto run() -> std::int32_t;
};

#endif // ! LAUNCHER_HPP
