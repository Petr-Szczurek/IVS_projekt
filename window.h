#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "math_lib.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow

{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void AllClearPressed();
    void BackspacePressed();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
