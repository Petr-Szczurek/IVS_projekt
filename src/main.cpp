#include "window.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
/**
 *   @file profiling.cpp
 *   @author Petr Szczurek
 *   @author Matous Huczala
 *   @author Martin Rybnikar
 *   @brief Hlavní funkce pro inicializaci aplikace a načtení překladů.
 */

/**
 * @brief Hlavní funkce aplikace.
 * @param argc Počet argumentů příkazové řádky.
 * @param argv Pole řetězců s argumenty příkazové řádky.
 * @return Návratová hodnota funkce.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator; 
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ivs_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Window w;
    w.show();
    return a.exec();
}