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

    /*
    //----------------------------------- Výstup -----------------------------------
    void on_Vystup_textChanged(const QString &arg1);

    //---------------------------------- Tlačítka ----------------------------------
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button4_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();

    //---------------------------------- Výpočty ----------------------------------
    void on_plusMinus_clicked();
    void on_decimal_clicked();
    void on_modulo_clicked();
    void on_sqrt_clicked();
    void on_pow_clicked();
    void on_factorial_clicked();
    void on_div_clicked();
    void on_mul_clicked();
    void on_sub_clicked();
    void on_sum_clicked();

    //----------------------------------- Mazání -----------------------------------
    void on_CE_clicked();
    void on_C_clicked();
    void on_backspace_clicked();
    void on_res_clicked();
    */

    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void AllClearPressed();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
