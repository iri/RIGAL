unit UseIbox;
{$S-}
{$R IB}
interface
uses WinTypes, WinProcs, WinDos, Strings;
const LB_MAX=50;
function DoInpBox(Window: HWnd;
  var RezData:string;Question: String): Boolean;
function DoListBox(Window: HWnd;
   var REZINT:integer;
   Question: String): Boolean;


function CreBox(Window: HWnd;
  var RezINT:integer;Question:String;var theBoxproc:longint;
      var thewin:word): Boolean;
function DelBox(theBoxProc:longint; thewin:word): Boolean;


function CreSTBox(Window: HWnd;
  var RezINT:integer;Question:String): Boolean;
procedure SetSTBox(i:longint);

function DelSTBox: Boolean;


var LB_ARR:array[1..LB_MAX]of pchar;
    LB_SIZE:integer;
implementation

const  id_Edit=101;
       id_Que =102;
       id_Quel=101;
       id_list=103;
var
  GQuestion,GRezData: array[0..80]of Char;

function InputDialog(Dialog: HWnd; Message, WParam: Word;
  LParam: longint): Bool; export;
begin
  InputDialog := True;
  case Message of
    wm_InitDialog:
      begin
        SendDlgItemMessage(Dialog, id_Edit, em_LimitText, 60, 0);
        SetDlgItemText(dialog,id_Que,GQuestion);
        SetDlgItemText(dialog,id_Edit,GRezData);
        SetFocus(GetDlgItem(Dialog, id_Edit));
        Exit;
      end;
    wm_Command:
      case WParam of
        id_Ok:
          begin
            GetDlgItemText(Dialog, id_Edit, GRezData, 61);
            EndDialog(Dialog, 1);
            Exit;
          end;
        id_Cancel:
          begin
            EndDialog(Dialog, 0);
            Exit;
          end;
      end;
  end;
  InputDialog := False;
end;

function DoInpBox(Window: HWnd;
  var RezData:string;Question:String): Boolean;
var
  DialogProc: TFarProc;
begin
  StrPcopy(GRezData,RezData);
  StrPcopy(GQuestion,Question);
  DialogProc := MakeProcInstance(@InputDialog, HInstance);
  DoInpBox := DialogBox(HInstance, 'IBOX', Window, DialogProc) = 1;
  FreeProcInstance(DialogProc);
  RezData:=StrPas(GRezData);
end;

{*********************** LIST  DIALOG **********************}
var ANS:integer;
function ListDialog(Dialog: HWnd; Message, WParam: Word;
  LParam: longint): Bool; export;
  var i:integer;
begin
  ListDialog := True;
  case Message of
    wm_InitDialog:
  begin
  SetDlgItemText(dialog,id_QueL,GQuestion);
  for i:=1 to LB_SIZE do begin
   SendDlgItemMessage(Dialog, id_List, lb_addstring,0,longint(LB_ARR[i]));
  end;
  SendDlgItemMessage(Dialog, id_List, lb_setcursel,0,0);
  SetFocus(GetDlgItem(Dialog, id_List));
  Exit;
      end;
    wm_Command:
      case WParam of
        id_Ok:
          begin
          {  GetDlgItemText(Dialog, id_Edit, GRezData, 61); }
            ANS:=SendDlgItemMessage(Dialog, id_List, lb_getcursel,0,0);
            EndDialog(Dialog, 1);
            Exit;
          end;
        id_List:
          begin
           if HiWord(LParam)=lbn_DblClk then begin
            ANS:=SendDlgItemMessage(Dialog, id_List, lb_getcursel,0,0);
            EndDialog(Dialog, 1);
            Exit;
            end;
          end;
        id_Cancel:
          begin
            EndDialog(Dialog, 0);
            Exit;
          end;
      end;
  end;
  ListDialog := False;
end;

function DoListBox(Window: HWnd;
  var RezINT:integer;Question:String): Boolean;
var
  DialogProc: TFarProc;
begin
  StrPcopy(GQuestion,Question);
  DialogProc := MakeProcInstance(@ListDialog, HInstance);
  DoListBox := DialogBox(HInstance, 'LBOX', Window, DialogProc) = 1;
  FreeProcInstance(DialogProc);
  RezINT:=ANS;
end;




{*********************** BOX DIALOG **********************}
var ANS2:integer;
var  theBoxWin:HWnd;


function BoxDialog(Dialog: HWnd; Message, WParam: Word;
  LParam: longint): Bool; export;
  var i:integer;
begin
  BoxDialog := True;
  case Message of
    wm_InitDialog:
  begin
  theboxwin:=Dialog;
  {showwindow(dialog,sw_maximize);}
  SetDlgItemText(dialog,id_QueL,GQuestion);
  for i:=1 to LB_SIZE do begin
   SendDlgItemMessage(Dialog, id_List, lb_addstring,0,longint(LB_ARR[i]));
  end;
  SendDlgItemMessage(Dialog, id_List, lb_setcursel,0,0);
  SetFocus(GetDlgItem(Dialog, id_List));
  BoxDialog := false;
  Exit;
end;
    wm_Command:
      case WParam of
        id_Ok:
          begin
          {  GetDlgItemText(Dialog, id_Edit, GRezData, 61); }
            ANS2:=SendDlgItemMessage(Dialog, id_List, lb_getcursel,0,0);
            EndDialog(Dialog, 1);
            Exit;
          end;
        id_List:
          begin
           if HiWord(LParam)=lbn_DblClk then begin
            ANS2:=SendDlgItemMessage(Dialog, id_List, lb_getcursel,0,0);
            EndDialog(Dialog, 1);
            Exit;
            end;
          end;
        id_Cancel:
          begin
            EndDialog(Dialog, 0);
            Exit;
          end;
      end;
  end;
  BoxDialog := False;
end;



function CreBox(Window: HWnd;
  var RezINT:integer;Question:String;var theBoxproc:longint;
      var thewin:word): Boolean;
Var
  DialogProc: TFarProc;
begin
  StrPcopy(GQuestion,Question);
  theBoxProc :=longint( MakeProcInstance(@BoxDialog, HInstance));
  CreBox := CreateDialog(HInstance, 'LBOX', Window, TFarProc(theBoxProc)) = 1;
  thewin:=theboxwin;
end;

function DelBox(theBoxProc:longint; thewin:word): Boolean;
var
  DialogProc: TFarProc;
begin
  DestroyWindow(theWin);
  FreeProcInstance(TFarProc(theboxproc));
end;






{*********************** ST BOX DIALOG **********************}


function STBoxDialog(Dialog: HWnd; Message, WParam: Word;
  LParam: longint): Bool; export;
  var i:integer;
begin
  STBoxDialog := True;
  case Message of
    wm_InitDialog:
  begin
(*  theboxwin:=Dialog; *)
  SetDlgItemText(dialog,id_QueL,GQuestion);
  Exit;
end;
  wm_Command:
      case WParam of
        id_Ok:
          begin
          {  GetDlgItemText(Dialog, id_Edit, GRezData, 61); }
            ANS2:=SendDlgItemMessage(Dialog, id_List, lb_getcursel,0,0);
            EndDialog(Dialog, 1);
            Exit;
          end;
        id_Cancel:
          begin
            EndDialog(Dialog, 0);
            Exit;
          end;
      end;
  end;
  STBoxDialog := False;
end;

var theSTboxProc:longint;
    theSTWin:Hwnd;

function CreSTBox(Window: HWnd;
  var RezINT:integer;Question:String): Boolean;
Var
  DialogProc: TFarProc;
begin
  StrPcopy(GQuestion,Question);
  theSTBoxProc :=longint( MakeProcInstance(@STBoxDialog, HInstance));
  theSTwin:= CreateDialog(HInstance, 'STBOX',
                          Window, TFarProc(theSTBoxProc));
  CreSTBox :=  theSTwin<>0;
end;

procedure SetSTBox(i:longint);
  begin
  SetDlgItemInt(theSTWin,105,i,false);
  end;


function DelSTBox: Boolean;
var
  DialogProc: TFarProc;
begin
  DestroyWindow(theSTWin);
  FreeProcInstance(TFarProc(theSTboxproc));
end;


end.
