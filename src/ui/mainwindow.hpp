#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui/widgets/rounded_window.hpp"
#include "ui/widgets/titlebar.hpp"
#include <QMainWindow>

class MainWindow : public UI::RoundedWindow {
  Q_OBJECT

private:
  QMainWindow window;
  TitleBar *m_titlebar;

  void setupTitleBar();

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() = default;
};

#endif // !MAINWINDOW_HPP
