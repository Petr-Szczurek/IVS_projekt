#include "window.h"
#include "./ui_window.h"

/**
 *   @file window.cpp
 *   @author Petr Szczurek
 *   @author Matous Huczala
 *   @author Martin Rybnikar
 * 
 *   @brief Deklarace proměnných
 */

double calcValue = 0.0; 
int intVal = 0;
int intVal_aff_but = 0;

double affter_butt_Val = 0;
bool scitani = false;
bool odcitani = false;
bool deleni = false;
bool nasobeni = false;
bool odmocnina = false;
bool na_x = false;
bool faktorial = false;
bool modulo = false;
bool decimal_nmb = false;

bool error = true;

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->Vystup->setText("");
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i) {
        QString butName = "button" + QString::number(i);
        numButtons[i] = Window::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this, SLOT(NumPressed()));
    }

    // sčítání, odčítání, dělení, násobení
    connect(ui->sum, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->sub, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->div, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->mul, SIGNAL(released()),this, SLOT(MathButtonPressed()));

    // odmocnina, mocnina, faktoriál, modulo
    connect(ui->odmocnina, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->pow, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->factorial, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->modulo, SIGNAL(released()),this, SLOT(MathButtonPressed()));

    // result, CE, C, backspace
    connect(ui->res, SIGNAL(released()),this, SLOT(EqualButtonPressed()));
    connect(ui->CE, SIGNAL(released()),this, SLOT(AllClearPressed()));
    connect(ui->backspace, SIGNAL(released()),this, SLOT(BackspacePressed()));

    // změna znaménka
    connect(ui->plus_minus, SIGNAL(released()),this, SLOT(Plus_minus_Pressed()));

    // decimal
    connect(ui->decimal, SIGNAL(released()),this, SLOT(DecimalPressed()));
}

Window::~Window()
{
    delete ui;
}

/**
 * @brief Funkce na stisknutí čísla
 */
void Window::NumPressed()
{
    QPushButton *button = (QPushButton *)sender(); ///<ukazatel na button, který vyvolal signál

    // hodnota clacitka se ulozi do BUTTON
    QString butVal = button->text();
    QString DISPLAY_VAL = ui->Vystup->text();
    if((DISPLAY_VAL.toDouble() == 0) || (DISPLAY_VAL.toDouble()))
    {
        ui->Vystup->setText(DISPLAY_VAL + butVal);
    }else{
        QString newVal = DISPLAY_VAL + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Vystup->setText(QString::number(dblNewVal, 'g', 16));
    }
}

/**
 * @brief Funkce na stisknutí matematické operace
 */
void Window::MathButtonPressed(){
    scitani = false;
    odcitani = false;
    deleni = false;
    nasobeni = false;

    odmocnina = false;
    na_x = false;
    faktorial = false;
    modulo = false;
    decimal_nmb = false;

    // Načtení hodnoty zobrazené na displeji a konverze na double nebo integer.
    QString displayVal = ui->Vystup->text();
    calcValue = displayVal.toDouble();
    intVal = displayVal.toInt();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    // Získání tlačítka, které bylo stisknuto, a jeho hodnoty.
    if(QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0){
        deleni = true;
    } else if(QString::compare(butVal, "×", Qt::CaseInsensitive) == 0){
        nasobeni = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        scitani = true;
    } else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        odcitani = true;
    }
    else if(QString::compare(butVal, "√ ", Qt::CaseInsensitive) == 0){
        odmocnina = true;
    }
    else if(QString::compare(butVal, "^", Qt::CaseInsensitive) == 0){
        na_x = true;
    }
    else if(QString::compare(butVal, "!", Qt::CaseInsensitive) == 0){
        faktorial = true;
    }
    else if(QString::compare(butVal, "%", Qt::CaseInsensitive) == 0){
        modulo = true;
    }
    // Vymazání zobrazené hodnoty na displeji.
    ui->Vystup->setText("");
}

/**
 * @brief Funkce na stisknutí znaku "=".
 */
void Window::EqualButtonPressed(){
    double vysledek = 0.0;
    int vysledek_fac = 0;

    QString displayVal = ui->Vystup->text();
    affter_butt_Val = displayVal.toDouble();
    intVal_aff_but = displayVal.toInt();

    if(nasobeni || deleni || scitani || odcitani || odmocnina || na_x || faktorial || modulo){
        if(scitani){
            vysledek = Math_lib::secti(calcValue, affter_butt_Val);
        }
        else if(odcitani){
            vysledek = Math_lib::odecitani(calcValue, affter_butt_Val);
        }
        else if(nasobeni){
            vysledek = Math_lib::nasobeni(calcValue, affter_butt_Val);
        }
        else if(deleni){
            error = Math_lib::deleni(calcValue, affter_butt_Val, &vysledek);
        }
        else if(na_x){
            vysledek = Math_lib::na_x(calcValue, affter_butt_Val);
        }
        else if(faktorial){
            error = Math_lib::faktorial(intVal, &vysledek_fac);
            vysledek = vysledek_fac;
        }
        else if(modulo){
            error = Math_lib::modulo(intVal, intVal_aff_but, &vysledek);
        }
        else if(odmocnina){
            error = Math_lib::odmocnina(calcValue, affter_butt_Val, &vysledek);
        }
    }

    if(error == false)
    {
        ui->Vystup->setText("Math Error");
        error = true;
    }else{
        ui->Vystup->setText(QString::number(vysledek));
    }

    // zjíštění jestli výsledek je desetinné číslo
    int pos = QString::number(vysledek).indexOf(".");

    // když není tečka v řetězci, vrátí -1
    if(pos == -1){
        decimal_nmb = false;
    }else{
        decimal_nmb = true;
    }
}

/**
 * @brief Funkce na stisknutí znaku CE.
 */
void Window::AllClearPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    if(QString::compare(butVal, "CE", Qt::CaseInsensitive) == 0){
        ui->Vystup->setText("");
        calcValue = 0.0;

        scitani = false;
        odcitani = false;
        deleni = false;
        nasobeni = false;

        odmocnina = false;
        na_x = false;
        faktorial = false;
        modulo = false;
        decimal_nmb = false;
    }
}

/**
 * @brief Funkce na stisknutí znaku Backspace. Odstraní ze stringu poslední znak.
 */
void Window::BackspacePressed(){
    QString DISPLAY_VAL = ui->Vystup->text();
    int delka = DISPLAY_VAL.size();

    // zjíštění jestli výsledek je desetinné číslo
    int pos = DISPLAY_VAL.indexOf(".");

    // když není tečka v řetězci vrátí -1
    if(pos == -1){
        decimal_nmb = false;
    }

    // pokud bude desetinná čárka smazána, musím mít možnost zadat ji znovu
    if(pos == delka-1){
        decimal_nmb = false;
    }

    DISPLAY_VAL.chop(1);
    ui->Vystup->setText(DISPLAY_VAL);
}

/**
 * @brief Funkce na stisknutí znaku Plus-Minus. Funkce převede hodnotu na stejnou hodnotu s opačným znaménkem.
 */
void Window::Plus_minus_Pressed(){
    QString displayVal = ui->Vystup->text();
    double hodnota = displayVal.toDouble();
    hodnota = 0 - hodnota;
    ui->Vystup->setText(QString::number(hodnota));
}

/**
 * @brief Funkce na stisknutí znaku desetinného čísla. Může být zmáčknuto pouze jednou během zadávání čísla. 
 */
void Window::DecimalPressed(){
    if(decimal_nmb == false){
        QString displayVal = ui->Vystup->text();
        displayVal = displayVal + ".";
        ui->Vystup->setText(displayVal);
        decimal_nmb = true;
    }
}