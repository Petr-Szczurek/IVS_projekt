#include "window.h"
#include "./ui_window.h"

double calcValue = 0.0;
int intVal = 0;

double affter_butt_Val = 0;
bool scitani = false;
bool odcitani = false;
bool deleni = false;
bool nasobeni = false;
bool odmocnina = false;
bool na_x = false;
bool faktorial = false;
bool modulo = false;

bool error = true;

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->Vystup->setText("Hallo");
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i) {
        QString butName = "button" + QString::number(i);
        numButtons[i] = Window::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this, SLOT(NumPressed()));
    }

    //scitani, odcitani, deleni, nasobeni
    connect(ui->sum, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->sub, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->div, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->mul, SIGNAL(released()),this, SLOT(MathButtonPressed()));

    //odmocnina, mocnina, faktorial, modulo
    connect(ui->sqrt, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->pow, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->factorial, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->modulo, SIGNAL(released()),this, SLOT(MathButtonPressed()));

    //result, CE, C, backspace
    connect(ui->res, SIGNAL(released()),this, SLOT(EqualButtonPressed()));
    connect(ui->CE, SIGNAL(released()),this, SLOT(AllClearPressed()));
    connect(ui->backspace, SIGNAL(released()),this, SLOT(BackspacePressed()));
}

Window::~Window()
{
    delete ui;
}

//stisknuti cisla
void Window::NumPressed()
{
    //ukazatel na button, ktery vyvolal signal
    QPushButton *button = (QPushButton *)sender();

    //hodnota clacitka se ulozi do BUTTON
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

//calcVal = na displaji pred math tlacitkem
void Window::MathButtonPressed(){
    scitani = false;
    odcitani = false;
    deleni = false;
    nasobeni = false;

    odmocnina = false;
    na_x = false;
    faktorial = false;
    modulo = false;

    QString displayVal = ui->Vystup->text();

    //kvuli faktorialu je potreba pouze int
    intVal = displayVal.toInt();
    calcValue = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    if(QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0){
        deleni = true;
    } else if(QString::compare(butVal, "×", Qt::CaseInsensitive) == 0){
        nasobeni = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        scitani = true;
    } else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        odcitani = true;
    }
    else if(QString::compare(butVal, "√", Qt::CaseInsensitive) == 0){
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

    ui->Vystup->setText("");
}

void Window::EqualButtonPressed(){
    double vysledek = 0.0;
    QString displayVal = ui->Vystup->text();
    affter_butt_Val = displayVal.toDouble();

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
            vysledek = Math_lib::faktorial(intVal);
        }
        else if(modulo){
            error = Math_lib::modulo(calcValue, affter_butt_Val, &vysledek);
        }
        else if(odmocnina){
            vysledek = Math_lib::odmocnina(calcValue, affter_butt_Val);
        }
    }

    if(error == false)
    {
        ui->Vystup->setText("Math Error");
        error = true;
    }else{
        ui->Vystup->setText(QString::number(vysledek));
    }

}

//Clear ALL
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
    }
}

//backspace, odstrani ze stringu posledni znak
void Window::BackspacePressed(){
    QString DISPLAY_VAL = ui->Vystup->text();
    DISPLAY_VAL.chop(1);
    ui->Vystup->setText(DISPLAY_VAL);
}


/*
//----------------------------------- Výstup -----------------------------------
void Window::on_Vystup_textChanged(const QString &arg1)
{
    //ui->Vystup->setText("dasdsa");
}

//---------------------------------- Tlačítka ----------------------------------

//Tlačítko 0
void Window::on_button0_clicked()
{
    ui->Vystup->setText("0");
}

//Tlačítko 1
void Window::on_button1_clicked()
{
    ui->Vystup->setText("1");
}

//Tlačítko 2
void Window::on_button2_clicked()
{
    ui->Vystup->setText("2");
}

//Tlačítko 3
void Window::on_button3_clicked()
{
    ui->Vystup->setText("3");
}

//Tlačítko 4
void Window::on_button4_clicked()
{
    ui->Vystup->setText("4");
}

//Tlačítko 5
void Window::on_button5_clicked()
{
    ui->Vystup->setText("5");
}

//Tlačítko 6
void Window::on_button6_clicked()
{
    ui->Vystup->setText("6");
}

//Tlačítko 7
void Window::on_button7_clicked()
{
    ui->Vystup->setText("7");
}

//Tlačítko 8
void Window::on_button8_clicked()
{
    ui->Vystup->setText("8");
}

//Tlačítko 9
void Window::on_button9_clicked()
{
    ui->Vystup->setText("9");
}

//---------------------------------- Výpočty ----------------------------------

//Tlačítko na změnu znaménka
void Window::on_plusMinus_clicked()
{
    ui->Vystup->setText("+/-");
}

//Tlačítko pro zapsání desetinné čárky
void Window::on_decimal_clicked()
{
    ui->Vystup->setText(",");
}

//Tlačítko pro výpočet modula
void Window::on_modulo_clicked()
{
    ui->Vystup->setText("%");
}

//Tlačítko pro výpočet odmocniny
void Window::on_sqrt_clicked()
{
    ui->Vystup->setText("sqrt");
}

//Tlačítko pro výpočet mocniny
void Window::on_pow_clicked()
{
    ui->Vystup->setText("pow");
}

//Tlačítko pro výpočet faktoriálu
void Window::on_factorial_clicked()
{
    ui->Vystup->setText("!");
}

//Tlačítko pro dělení
void Window::on_div_clicked()
{
    ui->Vystup->setText("/");
}

//Tlačítko pro násobení
void Window::on_mul_clicked()
{
    ui->Vystup->setText("*");
}

//Tlačítko pro odečítání
void Window::on_sub_clicked()
{
    ui->Vystup->setText("-");
}

//Tlačítko pro sčítání
void Window::on_sum_clicked()
{
    ui->Vystup->setText("+");
}

//----------------------------------- Mazání -----------------------------------

//Tlačítko pro smazání aktuálního řádku
void Window::on_CE_clicked()
{
    ui->Vystup->setText("CE");
}

//Tlačítko pro celkové smazání
void Window::on_C_clicked()
{
    ui->Vystup->setText("C");
}

//Tlačítko pro smazání jednoho znaku
void Window::on_backspace_clicked()
{
    ui->Vystup->setText("backspace");
}

//Tlačítko pro výpočet aktuálního řádku
void Window::on_res_clicked()
{
    ui->Vystup->setText("=");
}

*/
