#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include<QApplication>


TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){
    createWidgets();
    placeWidgets();
    currentTime=0;
    
    lights.append(redlight);
    lights.append(yellowlight);
    lights.append(greenlight);
    index = 0;
}


void TrafficLight::createWidgets()
{
    
    redlight = new QRadioButton;
    redlight->setEnabled(false);
    redlight->toggle();
    redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
    
    greenlight = new QRadioButton;
    greenlight->setEnabled(false);
    greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
    
    yellowlight = new QRadioButton;
    yellowlight->setEnabled(false);
    yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
    
    
    startTimer(10000);
}


void TrafficLight::placeWidgets()
{
    auto layout = new QVBoxLayout;
    layout->addWidget(redlight);
    layout->addWidget(greenlight);
    layout->addWidget(yellowlight);
    setLayout(layout);
}
void TrafficLight::timerEvent(QTimerEvent *e) {
    currentTime++;
    
    if(redlight->isChecked() && currentTime==4){
        greenlight->toggle();
        currentTime=0;
    }
    else if(greenlight->isChecked() && currentTime==1){
        yellowlight->toggle();
        currentTime=0;
    }
    else if (yellowlight->isChecked() && currentTime==2){
        redlight->toggle();
        currentTime =0;
        index = (index + 1) %3;
        lights[index]->toggle();
        
        if (redlight->isChecked())
            greenlight->toggle();
        else if(greenlight->isChecked())
            yellowlight->toggle();
        else if (yellowlight->isChecked())
            redlight->toggle();}}

void TrafficLight::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Escape)
        qApp->exit();
    if(e->key() == Qt::Key_R){
        index=0;
        lights[index]->toggle();
        
    } if(e->key()==Qt::Key_Y){
        index=1;
        lights[index]->toggle();
    }
    if(e->key() == Qt::Key_G){
        index=2;
        lights[index]->toggle();
    }
}
