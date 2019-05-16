#include "soldier.h"
#include "game.h"
#include <iostream>
#include "customrectitem.h"
#include "../../logic/GladiatorsList.h"
#include "../field.h"
#include <iostream>


Soldier::Soldier(QGraphicsRectItem* parent) {
    // Initializes default attributes.
}

/// Advances square ID in path.
void Soldier::advanceSquare() {
    this->currentSquare ++;
}

//! A method use to check soldiers damage
void Soldier::checkDamage() {
    if (life < 1) {
        this->setVisible(false);
    } else {
        Game* game = Game::getInstance();
        QList<QGraphicsItem*> colItems = collidingItems();
        QList<QGraphicsItem*> areas = game->getAreas();
        QList<QGraphicsItem*> intersection;

        for (int i = 0; i < colItems.length(); i++) {
            QGraphicsItem* item = colItems[i];
            for (int i = 0; i < areas.length(); i++) {
                QGraphicsItem* area = areas[i];
                if (area == item) {
                    intersection.append(area);
                }
            }
        }

        int damage = collidingItems().length();
        int size = intersection.size();
        if (size > 0) {
            qDebug() << "Made it" << size;
        }
        life-= damage;
    }
}

void Soldier::checkRotation() {
    Field* field = Field::getInstance();
    QList<int>* towers = field->towerList;
    QVector<CustomRectItem*> squares = field->allSquares;

    for (int i = 0; i < towers->length(); i++) {
        int towerID = towers->at(i);
        CustomRectItem* towerSquare = squares.at(towerID);
        QString rotationDir;
        QPixmap rPix;
        QPixmap rotationPix;
        QString towerType = towerSquare->towerType;

        int up = towers->at(i) - field->columns;
        int down = towers->at(i) + field->columns;
        int right = towers->at(i) + 1;
        int left = towers->at(i) - 1;
        int upLeft = up - 1;
        int upRight = up + 1;
        int downLeft = down - 1;
        int downRight = down + 1;

        if (graphicalSquare == up) {
            rotationDir = ":/towers/towers/" + towerType + "1b.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == down) {
            rotationDir = ":/towers/towers/" + towerType + "1f.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == right) {
            rotationDir = ":/towers/towers/" + towerType + "1d.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == left) {
            rotationDir = ":/towers/towers/" + towerType + "1.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == upLeft) {
            rotationDir = ":/towers/towers/" + towerType + "1a.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == upRight) {
            rotationDir = ":/towers/towers/" + towerType + "1c.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == downLeft) {
            rotationDir = ":/towers/towers/" + towerType + "1g.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        } else if (graphicalSquare == downRight) {
            rotationDir = ":/towers/towers/" + towerType + "1e.png";
            rPix = QPixmap(rotationDir);
            rotationPix = rPix.scaled(40,40);
            towerSquare->setBrush(rotationPix);
        }
    }
}

/// Sets damage to this soldier in cycle depending on position. Loop it for animated results.
void Soldier::damage() {
    if (life < 0) {
        Game* game = Game::getInstance();
        game->deleteSoldier(this);
    } else {
        Field* field = Field::getInstance();
        QList<int>* damageMatrix = field->damageMatrix;
        life -= damageMatrix->at(graphicalSquare);
        //qDebug() << life;
    }
}

//! A method that runs specific actions when a soldier is pressed
void Soldier::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsRectItem::mousePressEvent(event);
    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();
    gladiatorsList->setSoldierToShowByID(this->id);
    Field* field = Field::getInstance();
    field->setSoldierLabels();
}


