#include<iostream>
#include<cstdlib>

using namespace std;

 enum enlevel{Easy=1,Med=2,Hard=3,Mix=4};

 enum enoperationtype{Add=1,Sub=2,Mul=3,Div=4,mix=5};

 struct strquizz
 {
	 int NumOfQues = 0;
	 enlevel levelEn;
	 string QuesLevel = "";
	 enoperationtype operationtypeEn;
	 string TyoeOper = "";
	 int NumOfRightAnswers = 0;
	 int NumOfWrongAnswers = 0;
 };

 int ReadPositiveNumber(string massage)
 {
	 int num;

	 cout << massage << endl;
	 cin >> num;
	 while (num <= 0)
	 {
		 cout << "not true\n";
		 cout << massage << endl;
		 cin >> num;
	 }

	 return num;
 }

 int RandomNumber(int from, int to)
 {
	 int R_number = rand() % (to - from + 1) + from;
	 return R_number;
 }

 int ReadNumOfQuestions()
 {
	
	 return ReadPositiveNumber("How Many Question do you want to answer ? ");
 }

 enlevel Level()
 {
	 int level = 0;
	 cout << "Enter Questions Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
		 cin >> level;
		 return (enlevel)level;
 }

 enoperationtype OperationType()
 {
	 int type = 0;
	 cout << "Enter Operation Type [1]Add, [2]Sub,[3]Mul, [4]Div, [5]Mix ?";
	 cin >> type;
	 return (enoperationtype)type;
 }

 string EnumToStringForEnLevel(enlevel level)
 {
	 switch (level)
	 {
	 case enlevel::Easy:
		 return "Easy";
	 case enlevel::Hard:
		 return "Hard";
	 case enlevel::Med:
		 return "Med";
	 case enlevel::Mix:
		 return "Mix";

	 }
	 return "Unknown";
 }

 string EnumToStringForEnOperationType(enoperationtype OperationType)
 {
	 switch (OperationType)
	 {
	 case enoperationtype::Add:
		 return "Add";
	 case enoperationtype::Div:
		 return "Div";
	 case enoperationtype::mix:
		 return "Mix";
	 case enoperationtype::Mul:
		 return "Mul";
	 case enoperationtype::Sub:
		 return "Sub";
	 }
	 return "Unknown";
 }

 void GenarateQuestions(strquizz& quizz_person)
 {
	 int num1 = 0; int num2 = 0; int result = 0; int hisresult = 0;
	 enoperationtype tempoperation;

	 for (int i = 1; i <= quizz_person.NumOfQues; i++)
	 {
		 cout << "Queation [" << i << "/" << quizz_person.NumOfQues << "]\n";
	 switch (quizz_person.levelEn)
	 {
	 case enlevel::Easy:
		 num1 = RandomNumber(1, 10); num2 = RandomNumber(1, 10); 
		 break;
	 case enlevel::Med:
		 num1 = RandomNumber(10, 100); num2 = RandomNumber(10, 100); 
		 break;
	 case enlevel::Hard:
		 num1 = RandomNumber(100, 1000); num2 = RandomNumber(100, 1000);
		 break;
	 case enlevel::Mix:
		 num1 = RandomNumber(1, 300); num2 = RandomNumber(1, 300);
		 break;
	 
	 }
	 
	 tempoperation = quizz_person.operationtypeEn;

	 if (tempoperation == enoperationtype::mix)
		 tempoperation = (enoperationtype)RandomNumber(1, 4);

	 switch (tempoperation)
	 {
	 case enoperationtype::Add:
		 result = num1 + num2;
		 cout << num1 << endl << num2 << "+" << endl << "----------\n";
		 break;
	 case enoperationtype::Sub:
		 result = num1 - num2;
		 cout << num1 << endl << num2 << "-" << endl << "----------\n";
		 break;
	 case enoperationtype::Mul:
		 result = num1 * num2;
		 cout << num1 << endl << num2 << "*" << endl << "----------\n";
		 break;
	 case enoperationtype::Div:
		 result = num1 / num2;
		 cout << num1 << endl << num2 << "/" << endl << "----------\n";
		 break;
	 }

	 cin >> hisresult;
	 if (hisresult == result)
	 {
		 system("color 2f");
		 cout << "Right Answer :-)\n";
		 quizz_person.NumOfRightAnswers++;
	 }
	 else
	 {
		 system("color 4f");
		 quizz_person.NumOfWrongAnswers++;
		 cout << "Wrong answer :-(\n" << "the right aswer is: " << result << endl;

	 }
	 }
 }

 string CheckPass(strquizz quizz_person)
 {
	 if (quizz_person.NumOfRightAnswers >= quizz_person.NumOfQues/2)
		 return "PASS  :-)";
	 else
		 return "NOT PASS :-(";
 }

 void FinalShape(strquizz quizz_person)
 {
	 cout << "\n----------------------------------\n";
	 cout << "  FINAL RESULT IS " << CheckPass(quizz_person);
	 cout << "\n----------------------------------\n";
	 cout << "\n";
	 cout << "Number of Question: " << quizz_person.NumOfQues << endl;
	 cout << "Question Level       :" << quizz_person.QuesLevel << endl;
	 cout << "Op type                :" << quizz_person.TyoeOper << endl;
	 cout << "Number of Right Answer: " << quizz_person.NumOfRightAnswers << endl;
	 cout << "Number of Wrong Answer:   " << quizz_person.NumOfWrongAnswers << endl;
	 cout << "\n----------------------------------\n";

 }

 void ResetScreen()
 {
	 system("cls");
	 system("color 0f");

 }

 void Game()
 {
		 strquizz quizz_person;
		 quizz_person.NumOfQues = ReadNumOfQuestions();
		 quizz_person.levelEn = Level();
		 quizz_person.operationtypeEn = OperationType();
		 quizz_person.QuesLevel = EnumToStringForEnLevel(quizz_person.levelEn);
		 quizz_person.TyoeOper = EnumToStringForEnOperationType(quizz_person.operationtypeEn);
		 GenarateQuestions(quizz_person);
		 FinalShape(quizz_person);
 }

 void StartGame()
 {
	 char again = 'y';
	 do
	 {
		 ResetScreen();
			 Game();
		 cout << "Do you want play again? Y/N? ";
		 cin >> again;

	 } while (again == 'y' || again == 'Y');
 }


int main()
{
	srand((unsigned)time(NULL));
	StartGame();

}