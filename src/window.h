#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "math_lib.h"

/**
 *   @file window.h
 *   @authors Petr Szczurek
 *   @authors Matous Huczala
 *   @authors Martin Rybnikar
 * 
 *   @brief Deklarace třídy Window, která reprezentuje hlavní okno kalkulačky.
 */

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

/**
 * @brief Window reprezentuje hlavní okno kalkulačky.
 */
class Window : public QMainWindow

{
    Q_OBJECT
    

public:
/**
 * @brief Konstruktor třídy Window.
 *
 * @param parent Ukazatel na rodičovské okno.
 */
    Window(QWidget *parent = nullptr);
/**
 * @brief Destruktor třídy Window.
 */
    ~Window();

private slots:
/**
 * @brief Slot pro stisknutí tlačítka s číslem.
 */
    void NumPressed();

/**
 * @brief Slot pro stisknutí tlačítka s matematickou operací.
 */
    void MathButtonPressed();

/**
 * @brief Slot pro stisknutí tlačítka s rovnítkem.
 */
    void EqualButtonPressed();

/**
 * @brief Slot pro stisknutí tlačítka pro smazání všeho.
 */
    void AllClearPressed();

/**
 * @brief Slot pro stisknutí tlačítka mazání posledního znaku.
 */
    void BackspacePressed();

/**
 * @brief Slot pro stisknutí tlačítka pro změnu hodnoty čísla.
 */
    void Plus_minus_Pressed();

/**
 * @brief Slot pro stisknutí tlačítka přidání s desetinnou tečkou.
 */
    void DecimalPressed();
private:
    Ui::Window *ui; ///< Ukazatel na uživatelské rozhraní.
};

#endif // WINDOW_H
