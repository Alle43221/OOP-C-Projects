//
// Created by Ale on 21.05.2024.
//

#ifndef GAMING_STORE_GUI_H
#define GAMING_STORE_GUI_H


#include <QWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include "Service.h"

class GUI : public QWidget{
private:
    QListWidget* lista = new QListWidget();
    Service& srv;
    QPushButton* sort= new QPushButton("Sortare Pret");
    QPushButton* filter= new QPushButton("Jocuri recomandate pentru copii");
    QPushButton* refresh= new QPushButton("Refresh");
    QLabel* label= new QLabel;
    void init(){
        auto* Mainly=new QHBoxLayout();
        this->setLayout(Mainly);

        Mainly->addWidget(lista);
        auto Buttonsly=new QVBoxLayout();
        Mainly->addLayout(Buttonsly);
        Buttonsly->addWidget(label);
        Buttonsly->addWidget(sort);
        Buttonsly->addWidget(filter);
        Buttonsly->addWidget(refresh);
    }
    void connect(){
        QObject::connect(sort, &QPushButton::pressed, [=](){
            load(srv.sortPret());
        });
        QObject::connect(filter, &QPushButton::pressed, [=](){
            load(srv.filterRating(12));
        });
        QObject::connect(refresh, &QPushButton::pressed, [=](){
            load(srv.get_all());
        });
        QObject::connect(lista, &QListWidget::itemSelectionChanged, [=](){
            QList sel=lista->selectedItems();
            if(sel.empty()){
                label->setText("");
            }
            else{
                label->setText("PG Rating:" + sel[0]->data(Qt::UserRole).toString());

            }
        });
    }
    void load(vector<Joc> all){
        //vector<Joc> all=srv.get_all();
        lista->clear();
        for(auto i: all){
            string text = i.getTitlu() + " | " + to_string(i.getPret());
            auto* item=new QListWidgetItem;
            item->setText(QString::fromStdString(text));
            if(i.getPlatforma()=="PC"){
                item->setBackground(Qt::black);
            }else if(i.getPlatforma()=="PlayStation"){
                item->setBackground(Qt::blue);
            }
            else if(i.getPlatforma()=="XBOX"){
                item->setBackground(Qt::green);
            }
            else{
                item->setBackground(Qt::red);
            }
            item->setData(Qt::UserRole, i.getRating());
            lista->addItem(item);
        }
    }
public:
    GUI(Service &srv) : srv(srv) {
        init();
        load(srv.get_all());
        connect();
    }


};


#endif //GAMING_STORE_GUI_H
