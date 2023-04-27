#include "grammar.h"

void Grammar::clear()
{
    rule.clear();
}

void Grammar::initialGrammarList()
{

    // each row represents a unit layer

      grammarlist.append("FB[/&UU&FS]AWB[^^/USFS]AWW[*&FS]AW[//FS]AWW[&*FS]A$$C");
      grammarlist.append("FB[//FS]AWB[&&FS]AUW[**FS]AWW[//&FS]A$C");
      grammarlist.append("FB[/&UU&FS]AWB[^^/USFS]AWW[*&FS]AW[//FS]AWW[&*FS]A$$C");
      grammarlist.append("FB[/^US^FS]AUB[&*US*FS]AUW[*^^FS]AW[///FS]%C");
      grammarlist.append("FB[/&UU&FS]AWB[^^/USFS]AWW[*&FS]AW[//FS]AWW[&*FS]A$$C");
      grammarlist.append("FB[//FS]AWB[&&FS]AUW[**FS]AWW[//&FS]A$C");
      grammarlist.append("FB[/&UU&FS]AWB[^^/USFS]AWW[*&FS]AW[//FS]AWW[&*FS]A$$C");

      //grammarlist.append("FB[/^US^FS]AUB[&*US*FS]AUW[*^^FS]AW[///FS]%C");
      //
      //
      //grammarlist.append("FB[//FS]AWB[&&FS]AUW[**FS]AWW[//&FS]A$C");
      //grammarlist.append("FB[//FS]AWB[&&FS]AUW[**FS]AWW[//&FS]A$C");
      //grammarlist.append("FB[//FS]AWB[&&FS]AUW[**FS]AWW[//&FS]A$C");
}

void Grammar::Iteration() // genetrate the rule
{
    QString temprule = Startgrammar;//startgrammer=c
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//产生种子
    initialGrammarList();
    int num_grammar=grammarlist.size();

        for (int i = 1; i <= level; i++)//level是自己定义的
        {
            if( i == level){
                temprule += "[^UWX][&UWX]FX"; //如果所有layer生成完成
                continue;
            }
            int curlen = temprule.length();//获得当前rule的长度
            int j = 0;
            int last_idx=0;
            while (j < curlen)//把当前的的rule遍历一边
            {
                if (temprule[j] == "C")//move to the next ieration/layer c:添加新layer
                {
                    int idx=qrand() % (num_grammar-1);//生成小于num_grammar-1的随机数
                    if(last_idx == idx) idx=qrand() % (num_grammar-1); // prevent repeating
                    last_idx = idx;//最后生成一个和上一个last_idx不同的随机数
                    rule += grammarlist[idx];//随机抽一个grammarlist里的东西加到rule里
                    //qDebug()<<grammarlist[idx];
                    j++;
                }
                else if(temprule[j] == "S"){
                    rule += "[^UWX]U[&UWX]"; // sub for berry to grow 生成两个枝加葡萄
                    j++;
                }
                else
                {
                    rule += temprule[j];//不是s或者c就直接把temprule放到rule里
                    j++;
                }
            }
            temprule = rule;//把最后得到的rule放到temprule，完成这一层的生成
            rule.clear();
        }
        rule = temprule;//final output
}

void Grammar::setGrammarName(const QString &ref)
{
    Gname=ref;
}

void Grammar::setLevel(int num)
{
    level=num;
}

QString Grammar::getGrammarName()
{
    return Gname;
}

int Grammar::getLevel()
{
    return level;
}

QString Grammar::getRule() //return rule to the OpenGL
{
    return rule;
}

