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

   class A {
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

   class B {
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

  class C {
   private:
  A* a;
  B* b;
  public:
  C()
  {
  a = new A();
  b = new B();
  }

  ~C()
  {
  delete a;
  delete b;
  }

  void tabl() {
  a->tabl();
  b->tabl(); }
  };


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
      C *c = new C();

c->tabl();
 delete c;
}
