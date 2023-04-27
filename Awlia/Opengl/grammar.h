#ifndef GRAMMAR_H
#define GRAMMAR_H


#include <QString>
#include <QVector>
#include <vector>
#include <QTime>
#include <QtGlobal>
#include <QDebug>

class Grammar
{
public:
    QString Gname;  // Grammar name
    int level =16;        // iteration times, layer number
    QString Startgrammar = "C";
    QVector<QString> grammarlist;
    QString rule;   // iterated rule
    Grammar() {}    //constructor
    void clear();   // clear all the grammar
    void initialGrammarList();
    void Iteration();//iterate
    void setGrammarName(const QString& ref);
    void setLevel(int num);
    QString getGrammarName();
    int getLevel();
    QString getRule();
};

#endif // GRAMMAR_H
