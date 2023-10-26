#include "StdAfx.h"

namespace Logic
{
	

	 std::string isPalindromeText = " is a Palindrome!";
	 std::string notPalindromeText = " is not a Palindrome.";


void TestForPalindrome(System::Windows::Forms::RichTextBox^ box, System::Windows::Forms::Label^ responseBox, bool puntuations, bool numbers) {
	
	System::String ^ data = box->Text;
	std::string dataStd = msclr::interop::marshal_as< std::string >( data);
	System::String^ responseText;

	std::map<int,char> formattedMap;
	int palindromeErrorIndex = -1;

	if (puntuations && numbers) {
		formattedMap = StringFunctions::ToAlphaCharMap(dataStd);
		formattedMap = StringFunctions::CharMapToLower(formattedMap);
	}else if (puntuations && !numbers) {
		formattedMap = StringFunctions::ToAlphaNumCharMap(dataStd);
		formattedMap = StringFunctions::CharMapToLower(formattedMap);
	}else if (!puntuations && numbers) {
		formattedMap = StringFunctions::ToNonNumCharMap(dataStd);
	}else if (!puntuations && !numbers) {
		formattedMap = StringFunctions::ToCharMap(dataStd);
	}else {
		formattedMap = StringFunctions::ToCharMap(dataStd);
	}
	
	palindromeErrorIndex = (formattedMap.size() > 1) ? StringFunctions::GetPalindromeErrIndexFromMap(formattedMap) : 0;

	box->Text = "";
	box->Text = data;
	
	switch (palindromeErrorIndex) {
		case -1:
			responseText =  gcnew System::String(isPalindromeText.c_str());
			responseBox->ForeColor = System::Drawing::Color::Green;
			responseBox->Text = responseText;
		break;
		default:
			responseText =  gcnew System::String(notPalindromeText.c_str());
			HighlightItemsInRchTxtBox(box,palindromeErrorIndex);

			responseBox->ForeColor = System::Drawing::Color::Red;
			responseBox->Text = responseText;
		break;
	}
}

void HighlightItemsInRchTxtBox(System::Windows::Forms::RichTextBox^ box, int index){
	System::String ^ data = box->Text;

	wchar_t dataChar = data[index];
	wchar_t * P_dataChar = & dataChar;
	System::String ^ S_data = msclr::interop::marshal_as< System::String ^ >( P_dataChar );

	int indexLast = (data->Length - index) - 1;
	wchar_t dataCharLast = data[indexLast];
	wchar_t * P_dataCharLast = & dataCharLast;
	System::String ^ S_dataLast = msclr::interop::marshal_as< System::String ^ >( P_dataCharLast );
	
	box->Find(S_data, index, System::Windows::Forms::RichTextBoxFinds::MatchCase);
	box->SelectionBackColor = System::Drawing::Color::Yellow;

	box->Find(S_dataLast, indexLast, System::Windows::Forms::RichTextBoxFinds::MatchCase);
	box->SelectionBackColor = System::Drawing::Color::Yellow;
}

}