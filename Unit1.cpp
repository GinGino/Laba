//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <string.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

//Èñïîëüçóÿ øàáëîí äåëåãèðîâàíèÿ ðåàëèçîâàòü êëàññ âûâîäà òàáëè÷íûõ äàííûõ â StringGrid è â Memo

   class I {
public:
virtual void tabl() = 0;
};
   class A : public I{
  public:
  void tabl() {
  Form1->Memo1->Clear();
  Form1->Memo1->ScrollBars=ssVertical;
   int i, j;
   for(i = 1; i <= 4; i++)
   {
         for(j = 1; j <= 4; j++)
         {
            Form1->Memo1->Lines->Add("Ñòîëáåö "+IntToStr(i)+"  Ñòðîêà "+IntToStr(j));
            Form1->Memo1->Lines->Add("- - - - - - - - - - - - - - - - - - -");
            Form1->Memo1->Lines->Add("              "+IntToStr(i)+"+"+IntToStr(j)+"  ");
            Form1->Memo1->Lines->Add("- - - - - - - - - - - - - - - - - - -");
            }
        }
  }

   };

   class B : public I{
   public:
  void tabl() {
  int i, j;
  for(i = 1; i < Form1->StringGrid1->ColCount; i++)
  Form1->StringGrid1->Cells[i][0] = "Còîëáåö " + IntToStr(i);
  for(i = 1; i < Form1->StringGrid1->RowCount; i++)
 {
  Form1->StringGrid1->Cells[0][i] = "Còðîêà " + IntToStr(i);
  for(j = 1; j < Form1->StringGrid1->RowCount; j++)
  {
  Form1->StringGrid1->Cells[j][i] = IntToStr(i) + "+" + IntToStr(j);
  }
 }

  }
  };

  class C : public I{
  public:
C() : m_i ( new A() ) { }
virtual ~C() {
delete m_i;
}

void tabl() { m_i->tabl(); }
void toA() {
delete m_i;
m_i = new A();
}

void toB() {
delete m_i;
m_i = new B();
}
private:
I * m_i;
  };


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   C c;
  c.toA();
  c.tabl();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
C c;
c.toB();
c.tabl();
}
//---------------------------------------------------------------------------
