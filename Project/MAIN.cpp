//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2011 Media Design School
//
//  File Name   :   MAIN.cpp
//  Description :   Template for implementation (source) files
//  Author      :   Bryce Booth
//  Mail        :   brycebooth@mediadesign.school.nz
//

// Library Includes
// Local Includes
// This Include
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <stdarg.h>

using namespace std;

// Static Variables
int  g_iEmtpy = 0;
bool g_bEmtpy = 0;

int  g_iSizeOfInt  = static_cast<int>(sizeof(int));
int  g_iSizeOfChar = static_cast<int>(sizeof(char));

wchar_t const* g_kcWindowTitle = L"Extreme Battle Ships";

const int g_kiWindow_X = 124; //Even number reccomended
const int g_kiWindow_Y = 65;

const int g_kiWindowCenter_X = g_kiWindow_X / 2;
const int g_kiWindowCenter_Y = g_kiWindow_Y / 2;

const int g_kiGameBoard_Magnify_X = 5; //Mininum 1 : Max 5
const int g_kiGameBoard_Magnify_Y = 3;  //Mininum 1 : Max 4

const int g_kiGameBoard_X = 10;
const int g_kiGameBoard_Y = 10;

const int g_kiGameBoard_Magnified_X = g_kiGameBoard_X * g_kiGameBoard_Magnify_X;
const int g_kiGameBoard_Magnified_Y = g_kiGameBoard_Y * g_kiGameBoard_Magnify_Y;

const int g_kiHead_Y = 10;

const int g_kiContainer_Padding_X = 4;
const int g_kiContainer_Padding_Top_Y = 2;
const int g_kiContainer_Padding_Bot_Y = 2;

const int g_kiMenu_Indent_X = 3;
const int g_kiMenu_Sel_Deindent = 3;
const int g_kiMenu_Opt_Spacing_Y = 2;
const int g_kiMenu_Options_Max = 6;

const int g_kiMsgBoard_Boarder_Y = 1;
const int g_kiMsgBoard_Y = 4;
const int g_kiMsgBoard_Total_Y = g_kiMsgBoard_Y + (g_kiMsgBoard_Boarder_Y * 2);

const int g_kiShipLengths[] = { 2 , 3 , 3, 4 , 5 };
const int g_kiNumOfShips = 5;

const int g_kiShipBoard_TopLeft_X  = (g_kiWindow_X / 4) - (g_kiGameBoard_Magnified_X / 2);
const int g_kiEnemyBoard_TopLeft_X = g_kiShipBoard_TopLeft_X + (g_kiWindow_X / 2);
const int g_kiGameBoard_Top_Y = g_kiHead_Y + g_kiMsgBoard_Total_Y;

const int g_kiInstructionsBoard_Height = 10;

int g_iGameBoard[2][2][g_kiGameBoard_X][g_kiGameBoard_Y]; //[PlayerID][BoardID][BoardX][BoardY]
int g_iShipBoard[2][g_kiGameBoard_X][g_kiGameBoard_Y];    //[PlayerID][BoardX][BoardY]
int g_iPlayerShipsHealth[2][g_kiNumOfShips];              //[PlayerID][Ships Life]

const char g_kcBriefPart1[] = "Welcome Admiral,##You have been brought here to command the United States Imperial Battle#Fleet to defend our shores from an appending attack. Over the last decade,#scientists from this country have designed and created ships that could#strike given targets while being unmanned.";
const char g_kcBriefPart2[] = "By now you would have guessed that the ships are current not under our#control, ultimately now having a mind of their own. As we speak these#renegade ships are heading towards our shore line and they must be stopped#at all costs. We have managed to gather our finest fleet and they are#station in the direction of the incoming wave.";
const char g_kcBriefPart3[] = "Unfortunately the rogue ships are highly advanced and match your fleet in#firepower. Due to the estimated time of arrival, our other fleets will not#make it in time to support you in this battle. But we have full confidence#you will prevail again as you did in all your other victories against all#odds using your skill/determination and perseverance.##Good Luck Admiral!";

char g_cIntroductionBackGround[g_kiWindow_Y][g_kiWindow_X + 2];

bool g_bSoundOn = true;
bool g_bComputerSpeedNorm = true;

const int g_kiPlayer_Name_MaxLength = 15;
    char* g_cPlayer_Name;
    int   g_cPlayer_Name_Length;
	int   g_iCurrentPhase = 0;
	bool  g_bQuitGame = false;
	int   g_Game_NumRounds = 0;
	int   g_Game_Winner = -1;

enum GAME_KEYS {
	eARROW_UP    = 72,
	eARROW_DOWN  = 80,
	eARROW_LEFT  = 75,
	eARROW_RIGHT = 77,
	eSPACEBAR    = 32,
	eENTER       = 13,
	eESCAPE      = 27
};
enum TEXT_COLOURS {
	

	eD_BLUE   = 1,
	eL_BLUE   = 9,

	eD_GREEN  = 2,
	eL_GREEN  = 10,

	eD_TEAL   = 3,
	eL_TEAL   = 10,

	eD_RED    = 4,
	eL_RED    = 12,

	eD_PURPLE = 5,
	eL_PURPLE = 13,

	eD_GRAY = 8,
	eL_GRAY = 7,

	eBROWN   = 6,
	eYELLOW  = 14,
	eWHITE   = 15,
	eBLINK   = 128,
};
enum PLAYERS {
	ePLAYER_HUMAN,
	ePLAYER_COMPUTER,
	ePLAYER_WINNER
};
enum BOARDS {
	eBOARD_SHIPS,
	eBOARD_ENEMY
};
enum SOUNDS
{
	eSND_SMLEXPLOSION1,
	eSND_SMLEXPLOSION2,
	eSND_SELECT,
	eSND_ERROR,
	eSND_LASER,
	eSND_LRGEXPLOSION,
	eSND_HITWATER,
	eSND_TICK,
	eSND_ROTATE
};
enum MENU_OPTIONS
{
	ePLAY_GAME = 0,
	eBRIEFING  = 1,
	eOPTIONS   = 2,
	eQUIT_GAME = 3,

	eMANUAL_PLACE = 0,
	eAUTO_PLACE   = 1,
	eBACK_MAIN    = 2,

	eCOMP_AI = 0,
	eSOUND   = 1,

	eCOMP_NORM = 0,
	eCOMP_FAST = 1,

	eSOND_ON  = 0,
	eSOND_OFF = 1,

	eRESUME_GAME = 0,
	eIN_GAME_OPTS = 1,
	eIN_GAME_MAIN_MENU = 2
};
enum GAME_PHASE {
	eMAIN_MENU,
	eGAME_INTRO,
	eIN_GAME,
	eIN_GAME_MENU
};

struct OBJECT {
	unsigned int  ID;          //Object ID
	unsigned char Char;        //Character
	unsigned int  Char_Colour; //Character Colour
	unsigned int  BG_Colour;   //Background Colour
};

const OBJECT tWATER                = {  1 ,  176 , eL_TEAL   , eL_BLUE  };
      OBJECT tSHIP                 = {  2 ,  219 , eL_GRAY  , 0       };
const OBJECT tHIT_WATER            = {  3 ,  176 , eD_TEAL   , eL_BLUE  };
const OBJECT tHIT_SHIP             = {  4 ,  219 , eL_RED    , 0       };
const OBJECT tDESTROYED_SHIP       = {  5 ,  ' ' , eD_RED    , eD_RED   };
const OBJECT tGAMEBOARD_BG         = {  6 ,  ' ' , eD_TEAL   , eL_BLUE  };
const OBJECT tCOORDCURSOR          = {  7 ,  219 , eYELLOW , 0       };
const OBJECT tCOORDCURSOR_SEL      = {  8 ,  ' ' , eWHITE  , eL_GREEN };
const OBJECT tMSG_BOARD            = {  9 ,  ' ' , eWHITE  , eD_GREEN };
const OBJECT tMSG_BOARD_BOARDER    = { 10 ,  ' ' , eL_GREEN  , eD_GREEN };
const OBJECT tMSG_BOARD_PLAYERINFO = { 11 ,  219 , eWHITE  , tMSG_BOARD.BG_Colour };
const OBJECT tPLAYER_NAME          = { 12 ,  ' ' , eWHITE  , tGAMEBOARD_BG.BG_Colour };
const OBJECT tCONT_BORDER          = { 13 ,  205 , eWHITE  , eL_RED };
const OBJECT tCONT_BORDER_HOR      = { 14 ,  205 , eWHITE  , eL_RED };
const OBJECT tCONT_BORDER_VERT     = { 15 ,  186 , eWHITE  , eL_RED };
const OBJECT tCONT_BODY            = { 16 ,  ' ' , eWHITE  , eD_RED };
const OBJECT tCONT_TITLE           = { 17 ,  196 , eYELLOW , eD_RED };
const OBJECT tMENU_SELECT          = { 18 ,  175 , eL_TEAL   , eD_RED };
const OBJECT tEMPTY                = { 0 , 0 , 0 , 0 };

OBJECT GetObject(OBJECT _tToSet, int _iObjectID = 0)
{
	int iSearchObjectID = 0;

	if (_iObjectID != 0) {
		iSearchObjectID = _iObjectID;
	}
	else {
		iSearchObjectID = _tToSet.ID;
	}

	switch (iSearchObjectID)
	{
	case 1:
		return tWATER;
	case 2:
		return tSHIP;
	case 3:
		return tHIT_WATER;
	case 4:
		return tHIT_SHIP;
	case 5:
		return tDESTROYED_SHIP;
	case 6:
		return tGAMEBOARD_BG;
	case 7:
		return tCOORDCURSOR;
	case 8:
		return tCOORDCURSOR_SEL;
	case 9:
		return tMSG_BOARD;
	case 10:
		return tMSG_BOARD_BOARDER;
	case 11:
		return tMSG_BOARD_PLAYERINFO;
	case 12:
		return tPLAYER_NAME;
	case 13:
		return tCONT_BORDER;
	case 14:
		return tCONT_BORDER_HOR;
	case 15:
		return tCONT_BORDER_VERT;
	case 16:
		return tCONT_BODY;
	case 17:
		return tCONT_TITLE;
	case 18:
		return tMENU_SELECT;
	default:
		return tWATER;
	}
}

// Static Function Prototypes
void SetupIntroBackGround();
void DisplayIntroBackGround(int _iStartX = 0, int _iStartY = 0, int _iWidth = 0, int _iHeight = 0);

void SetupConsoleWindow();
void HideCursor(bool _bHide = false);
void ClearInputBuffer();
char GetInput(const char _kcAllowedChars[], char cSingleKey = '\0');
void SetColour(OBJECT _tToSet = tEMPTY, int _iTextColour = -1, int _iBGColour = -1);
void SetCursorPosition(int _iX, int _iY);
void GetCursorPosition(int& _iX, int& _iY);
int  GenerateRandomNumber(int _iMin, int _iMax);
void PlayGameSound(int SoundID);

void CreateContainer(const char _kcTitle[], int _iWidth, int _iHeight, int _iPosX , int _iPosY, OBJECT _tBody = tCONT_BODY, OBJECT _tBoarder_Horiz = tCONT_BORDER_HOR, OBJECT _tBoarder_Vert = tCONT_BORDER_VERT);
void AddContainerCorners(int _iWidth, int _iHeight, int _iPosX, int _iPosY);
void AddContainerTitle(const char _kcTitle[]);
void RemoveLastContainer(int _iPosX = 0, int _iPosY = 0, int _iWidth = 0, int _iHeight = 0);

int  CreateMenu(const char _kcTitle[], int _iPosX, int _iPosY, int _iNumOptions, ... );
int  GetMenuLongestStrLength(const char _kcMyString[], bool _bReset = false);
void AddMenuOption(const char _kcpOption[], int _iOptNum, bool _bReset = false);
void SelectMenuOption(int _iStartingX, int _iStartingY, int _iOptionNum, bool _bReset = false);
int  GetMenuOptionSelection(int _iStartingX, int _iStartingY, int _iNumOptions);

void DisplayPressSpaceToStart();
void DisplayGetPlayerNameMenu();
void DisplayBriefing();
void DisplayOptionsMenu();
bool DisplayShipPositioningMenu();

void DisplayControls(int _iControlType);
void DisplayNotification(const char _kcMessage[]);
void DisplayMessage(const char _kcTitle[] = "", const char _kcMessage[] = "");
void DisplayWelcomeMessage();
void DisplayInGameMenu();

void ClearPlayerBoard(int _iPlayerID, bool _bBoard);
void ClearShipBoard(int _iPlayerID);
void ResetGameVariables();
void ShowGameBoardBG();
void ShowGameBoard(int _iPlayerID, bool _bRefreshBoatsOnly = false, int _iBoard = -1);
void HighlightPlayerShips(int _iPlayerID, int _iColour = eL_GREEN);
void MarkShipAsDesroyed(int _iPlayerID, int _iShipID);

void BeginHumanTurn();
void BeginPlacingShips();
void BeginGeneratingShips();
void SelectCoordinate(bool _bBoard , int& _iX , int& _iY , bool& _bO = g_bEmtpy, int _iExtension = 1);
void ReplaceGameBoardSection(int _iPlayerID, bool _bBoard, int _iX, int _iY, bool _bO = false, OBJECT _tToSet = tEMPTY, int _iExtension = 1);

bool SearchForHitShip(int& _iShipX, int& _iShipY);
void AttackRandomCoordinates(int& _iHitShipID, int& _iShipPosX, int& _iShipPosY, bool& _bIsShipDestoyed);
void AttackRandomSurroundingCoordinates(int& _iTargetShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed);
bool AttackRandomHorizontalCoordinates(int& _iHitShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed);
bool AttackRandomVerticalCoordinates(int& _iHitShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed);
void PlayCoordinateAnimation(int _iStartX, int _iStartY, int _iDestX, int _iDestY);

void GenerateShipPositions(int _iPlayerID);
void PlaceShip(int _iPlayerID, int _iShipSize, int _iShipID, int _iX, int _iY, bool _bO);
void BeginComputerTurn();
void BeginHumanTurn();
bool AttackCoorinates(int _iPlayerID, int& _iHitShipID, int _iX , int _iY, bool& _bShipDestoryed);

bool IsShipPositionValid(int _iPlayerID, int _iShipSize, int _iX, int _iY, bool _bO);
bool IsCoordinatesAShip(int _iPlayerID, int _iX, int _iY);
bool HasCoordinatesBeenAttacked(int _iPlayerID, int _iX, int _iY);
bool IsThereAWinner();
void CheckForBug();

// Implementation
int main()
{
	SetupConsoleWindow();

	int  iMenuSelectedOption = 0;
	bool bStartGame = false, bQuitGame = false;

	while (bQuitGame == false)
	{
		bStartGame = false;

		ResetGameVariables();
		SetupIntroBackGround();
		DisplayIntroBackGround();

		g_iCurrentPhase = eMAIN_MENU;
		DisplayPressSpaceToStart();

		do
		{
			iMenuSelectedOption = CreateMenu( "Main Menu" , 7 , -1 , 4 , "Play Game" , "Briefing" , "Options" , "Quit Game" );
			switch (iMenuSelectedOption)
			{
			case ePLAY_GAME:
				bStartGame = true;
				break;

			case eBRIEFING:
				DisplayBriefing();
				break;

			case eOPTIONS:
				DisplayOptionsMenu();
				break;

			default: // eQUIT_GAME
				bQuitGame = true;
				break;
			}

			iMenuSelectedOption = 0;

			if (bQuitGame == true) {
				break;
			}
		}
		while (bStartGame == false);
	
		if (bStartGame == true)
		{
			DisplayGetPlayerNameMenu();

			DisplayMessage( "U.S Command" , "Welcome &PN,##You are about to receive footage from#our satellites of the engagement zone.#" );

			g_iCurrentPhase = eGAME_INTRO;
			ShowGameBoard( ePLAYER_HUMAN );

			DisplayNotification( "*Uplink Successful*" );
			DisplayMessage( "U.S Command" , "The board on the LEFT is the area#your ships are currently located.#" );
			DisplayMessage( "U.S Command" , "Which leaves the location of the enemy#ships somewhere on the RIGHT board.#" );

			iMenuSelectedOption = DisplayShipPositioningMenu();

			ShowGameBoard( ePLAYER_HUMAN ); //Refresh

			DisplayMessage( "U.S Command" , "The controls for sending commands to your#ships are located under the Game Board.#" );

			if (iMenuSelectedOption == eMANUAL_PLACE) {
				DisplayControls(1);
				BeginPlacingShips();
			}
			else if (iMenuSelectedOption == eAUTO_PLACE) {
				DisplayControls(2);
				BeginGeneratingShips();
			}

			HighlightPlayerShips( ePLAYER_HUMAN );
			GenerateShipPositions( ePLAYER_COMPUTER );

			DisplayMessage( "U.S Command" , "Your fleet has been positioned!#" );
			DisplayMessage( "U.S Command" , "The enemy ships have arrived!#" );
			DisplayMessage( "U.S Command" , "Prepare for battle!#" );

			g_iCurrentPhase = eIN_GAME;
			DisplayControls(3);
			do
			{
				CheckForBug();
				BeginHumanTurn();
				if (g_bQuitGame == true) {
					break;
				}
				if (IsThereAWinner() == true) {
					break;
				}
				BeginComputerTurn();
				if (g_bQuitGame == true) {
					break;
				}
				if (IsThereAWinner() == true) {
					break;
				}
			}
			while (IsThereAWinner() == false);
			
			if (g_Game_Winner != -1) {
				if (g_Game_Winner == ePLAYER_HUMAN) {
					DisplayMessage( "U.S Command" , "Congratulations! You have saved the entire human race from extinction!# #Well done &PN!#" );
				}
				else {
					DisplayMessage( "U.S Command" , "You have been defeated.##May god have mercy on our souls...#" );
				}
			}
		}

	}

	return(0);
}

/*Global Functions*/
/**
*
* Sets the console window settings for the game
* Title/Window Buffer/Info Size
*
* @author Bryce Booth
*
*/

void SetupConsoleWindow()
{
	SetConsoleTitle(g_kcWindowTitle);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD tBuffer = { g_kiWindow_X , g_kiWindow_Y };
	SetConsoleScreenBufferSize( hConsole , tBuffer );

	SMALL_RECT tDisplayArea = { 0 , 0 , (g_kiWindow_X - 1) , (g_kiWindow_Y - 1) };
    SetConsoleWindowInfo( hConsole , TRUE, &tDisplayArea );

	HideCursor(true);

	system("color 1f");
}
/**
*
* Hides/Shows Console Cursor
*
* @author Bryce Booth
* @param Hide Cursor
*
*/
void HideCursor(bool _bHide)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (_bHide == true) {
		CONSOLE_CURSOR_INFO tCursor = { 1 , FALSE };
		SetConsoleCursorInfo( hConsole , &tCursor );
	}
	else {
		CONSOLE_CURSOR_INFO tCursor = { 1 , TRUE };
		SetConsoleCursorInfo( hConsole , &tCursor );
	}
}
/**
*
* Clears the input buffer to prevent delayed spamming of keys
*
* @author Bryce Booth
*
*/
void ClearInputBuffer()
{
	unsigned char ucTemp = '\0';

	while (true)
	{
		if (_kbhit() == false) {
			break;
		}
		ucTemp = _getch();
	}
}
/**
*
* Retrieves a allowed input key from user
* Escape key is by default checked
*
* @author Bryce Booth
* @param Keys that will be accepted
* @param A single key that will be accepted
*
*/
char GetInput(const char _kcAllowedChars[], char cSingleKey)
{
	ClearInputBuffer();

	size_t ArraySize = strlen(_kcAllowedChars);

	unsigned char ucInput = '\0';

	while (true)
	{
		ucInput = _getch();

		if (cSingleKey != '\0' && ucInput == cSingleKey) {
			return true;
		}

		if (ucInput == eESCAPE && g_iCurrentPhase == eIN_GAME) {
			g_iCurrentPhase = eIN_GAME_MENU;
			DisplayInGameMenu();
			g_iCurrentPhase = eIN_GAME;
			continue;
		}

		for (int I = 0; I < static_cast<int>(ArraySize); ++ I)
		{
			if (_kcAllowedChars[I] == ucInput) {
				return ucInput;
			}
		}
	}
}
/**
*
* Sets the console text colour and background text colour
*
* @author Bryce Booth
* @param Game object from struct OBJECT
* @param Over-ride text colour number
* @param Over-ride background colour number
*
*/
void SetColour(OBJECT _tToSet, int _iTextColour, int _iBGColour)
{
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

	int iTextColour = 0, iBackgroundColour = 0;

	if (_iTextColour == -1) {
		iTextColour = _tToSet.Char_Colour;
		iBackgroundColour = _tToSet.BG_Colour;
	}
	else {
		iTextColour = _iTextColour;
		iBackgroundColour = 0;

		if (_iBGColour != -1) {
			iBackgroundColour = _iBGColour;
		}
	}

	if (iTextColour != 0 && iBackgroundColour == 0) {
		SetConsoleTextAttribute( hConsole , iTextColour );
	}
	else if (iTextColour == 0 && iBackgroundColour != 0) {
		SetConsoleTextAttribute( hConsole , ( iBackgroundColour * 16 ) );
	}
	else if (iTextColour != 0 && iBackgroundColour != 0) {
		SetConsoleTextAttribute( hConsole , iTextColour | ( iBackgroundColour * 16 ) );
	}
}
/**
*
* Moves the console cursor to X , Y
*
* @author Bryce Booth
* @param X Coordinate
* @param Y Coordinate
*
*/
void SetCursorPosition(int _iX, int _iY)
{
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

	COORD tPoint = { _iX , _iY };

	SetConsoleCursorPosition( hConsole , tPoint );
}
void GetCursorPosition(int& _iX, int& _iY)
{
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(hConsole, &SBInfo);

	_iX = SBInfo.dwCursorPosition.X;
	_iY = SBInfo.dwCursorPosition.Y;
}
/**
*
* Generates a random number between numbers
*
* @author Bryce Booth
* @param Lowest number to return
* @param Heighest number to return
*
*/
int  GenerateRandomNumber(int _iMin , int _iMax)
{
	return (_iMin + rand() % _iMax);
}
/**
*
* Plays a game sound
*
* @author Bryce Booth
* @param Sound ID to play
*
*/
void PlayGameSound(int SoundID)
{
	static bool bDisableSounds = true;
	
	if (bDisableSounds == true) {
		return;
	}

	if (g_bSoundOn == false) {
		return;
	}

	char cFileName[20];
	
	switch (SoundID)
	{
	case eSND_SMLEXPLOSION1:
		strcpy_s(cFileName, "SmallExplosion1.wav");
		break;
	case eSND_SMLEXPLOSION2:
		strcpy_s(cFileName, "SmallExplosion2.wav");
		break;
	case eSND_SELECT:
		strcpy_s(cFileName, "Select.wav");
		break;
	case eSND_ERROR:
		strcpy_s(cFileName, "Error.wav");
		break;
	case eSND_LASER:
		strcpy_s(cFileName, "MenuSelect.wav");
		break;
	case eSND_LRGEXPLOSION:
		strcpy_s(cFileName, "LargeExplosion.wav");
		break;
	case eSND_HITWATER:
		strcpy_s(cFileName, "HitWater.wav");
		break;
	case eSND_TICK:
		strcpy_s(cFileName, "Tick.wav");
		break;
	case eSND_ROTATE:
		strcpy_s(cFileName, "Rotate.wav");
		break;
	default:
		return;
	}

	char cSoundAddress[100];

	strcpy_s(cSoundAddress, "C:\\");
	strcat_s(cSoundAddress, cFileName);

	wchar_t wideSoundAddress[100];
	
	for (int i = 0; i < 100; ++i)
	{
		wideSoundAddress[i] = cSoundAddress[i];
	}

	PlaySound(wideSoundAddress, NULL, SND_ASYNC );
}

/*Container*/
/**
*
* Creates an in-game container for menus or text
*
* @author Bryce Booth
* @param Title of the container
* @param Width of the container
* @param Height of the container
* @param Top-left X position of the container
* @param Top-left Y position of the container
* @param Object to use for text inside the container
* @param Object to use for the hroizontal boarder 
* @param Object to use for the Vetical boarder 
*
*/
void CreateContainer(const char _kcTitle[], int _iWidth, int _iHeight, int _iPosX , int _iPosY, OBJECT _tBody, OBJECT _tBoarder_Horiz, OBJECT _tBoarder_Vert)
{
	_iWidth += g_kiContainer_Padding_X * 2;

	if (strlen(_kcTitle) != 0) {
		_iHeight += 3; //Title Height
	}
	_iHeight += g_kiContainer_Padding_Top_Y + g_kiContainer_Padding_Bot_Y; //Boarder Height

	if (_iPosX == -1) { //Center
		_iPosX = (g_kiWindow_X / 2) - (_iWidth / 2);
	}

	if (_iPosY == -1) { //Center
		_iPosY = (g_kiWindow_Y / 2) - (_iHeight / 2);
	}

	//Back Ground//
	OBJECT tToSet;
	for (int iY = 0; iY < _iHeight; ++ iY)
	{
		SetCursorPosition( _iPosX , _iPosY + iY );

		for (int iX = 0; iX < _iWidth; ++ iX)
		{
			if (iY == 0 || iY == (_iHeight - 1)) {
				tToSet = GetObject(_tBoarder_Horiz);
			}
			else if (iX == 0 || iX == (_iWidth - 1)) {
				tToSet = GetObject(_tBoarder_Vert);
			}
			else {
				tToSet = GetObject(_tBody);
			}

			SetColour(tToSet);
			cout << tToSet.Char;
		}
	}

	//Boarder Corners//
	AddContainerCorners( _iWidth , _iHeight , _iPosX , _iPosY );

	SetCursorPosition( _iPosX + g_kiContainer_Padding_X , _iPosY + g_kiContainer_Padding_Top_Y );

	if (strlen(_kcTitle) != 0) {
		AddContainerTitle( _kcTitle );
	}

	RemoveLastContainer( _iPosX ,  _iPosY,  _iWidth ,  _iHeight );

	SetColour(_tBody);
}
/**
*
* Adds the special corners to the container
*
* @author Bryce Booth
* @param Width of the container
* @param Height of the container
* @param Top-left X position of the container
* @param Top-left Y position of the container
*
*/
void AddContainerCorners(int _iWidth, int _iHeight, int _iPosX, int _iPosY)
{
	OBJECT tToSet;

	tToSet = GetObject(tCONT_BORDER);
	SetColour(tToSet);

	-- _iWidth;
	-- _iHeight;

	unsigned char ucBoarders[] = { 201 , 187 , 200 , 188 };

	for (int I = 0; I < 4; ++ I)
	{
		switch (I)
		{
		case 0:
			SetCursorPosition( _iPosX , _iPosY );
			break;
		case 1:
			SetCursorPosition( _iPosX + _iWidth , _iPosY );
			break;
		case 2:
			SetCursorPosition( _iPosX , _iPosY + _iHeight);
			break;
		case 3:
			SetCursorPosition( _iPosX + _iWidth , _iPosY + _iHeight);
			break;
		}

		cout << ucBoarders[I];
	}
}
/**
*
* Adds the title for the container
*
* @author Bryce Booth
* @param Title of the container
*
*/
void AddContainerTitle(const char _kcTitle[])
{
	int iTempX = 0, iTempY = 0;

	GetCursorPosition( iTempX , iTempY );

	-- iTempX; //Indent

	SetCursorPosition( iTempX , iTempY );

	OBJECT tToSet;
	tToSet = GetObject(tCONT_TITLE);
	SetColour(tToSet);

	cout << _kcTitle;

	SetCursorPosition( iTempX , iTempY + 1 );

	int TitleLength = static_cast<int>(strlen(_kcTitle));

	for (int I = 0; I < TitleLength; ++I) {
		cout << tToSet.Char;
	}

	++ iTempX; //Indent Restore

	SetCursorPosition( iTempX , iTempY + 3 );
}
/**
*
* Removes the last created container from the game
*
* @author Bryce Booth
* @param Width of the container
* @param Height of the container
* @param Top-left X position of the container
* @param Top-left Y position of the container
*
*/
void RemoveLastContainer(int _iPosX , int _iPosY, int _iWidth, int _iHeight)
{
	static int iPosX = 0;
	static int iPosY = 0;
	static int iWidth = 0;
	static int iHeight = 0;

	if (_iPosX != 0 && _iWidth != 0) {
		iPosX = _iPosX;
		iPosY = _iPosY;
		iWidth = _iWidth;
		iHeight = _iHeight;
	}
	else {
		DisplayIntroBackGround( iPosX , iPosY , iWidth , iHeight );
	}
}

/*Menus*/
/**
*
* Creates dynamic menus with options
*
* @author Bryce Booth
* @param Title of menu
* @param Top-left X position of the container
* @param Top-left Y position of the container
* @param Number of options to be added to the menu
* @param The variable amount of options for menu
*
*/
int  CreateMenu(const char _kcTitle[], int _iPosX, int _iPosY, int _iNumOptions, ... )
{
	//Find Required Width & Height For Menu//
	int iWidth = 0, iHeight = 0;

	va_list Input = 0;
	va_start( Input , _iNumOptions );

	char cOptions[g_kiMenu_Options_Max][40];
	int  iLongestStrLength = 0;

	for (int iOptNum = 0; iOptNum < _iNumOptions ; ++ iOptNum)
	{
		const char* kcpOption = va_arg( Input , const char* );
		memcpy( cOptions[iOptNum] , kcpOption , strlen(kcpOption) + 1 );

		if (iOptNum == 0) {
			iLongestStrLength = GetMenuLongestStrLength( cOptions[iOptNum] , true );
		}
		else {
			iLongestStrLength = GetMenuLongestStrLength( cOptions[iOptNum] );
		}
	}

	va_end(Input);

	iWidth  = g_kiMenu_Indent_X + iLongestStrLength + 3;
	iHeight = (g_kiMenu_Opt_Spacing_Y * _iNumOptions);

	//Create Menu Container//
	CreateContainer( _kcTitle , iWidth , iHeight , _iPosX , _iPosY );

	int iStartingX = 0, iStartingY = 0;
	GetCursorPosition( iStartingX , iStartingY );

	//Add Options//
	for (int I = 0; I < _iNumOptions; ++I) {
		if (I == 0) {
			AddMenuOption( cOptions[I] , I , true);
		}
		else {
			AddMenuOption( cOptions[I] , I);
		}
		
	}

	int iSelectedOptNum = 0;
	iSelectedOptNum = GetMenuOptionSelection( iStartingX , iStartingY, _iNumOptions );

	RemoveLastContainer();

	return iSelectedOptNum;
}
/**
*
* Finds the longest option string name for the new menu to set the container width with.
*
* @author Bryce Booth
* @param Option String
* @param Reset default varaibles for new menu
*
*/
int  GetMenuLongestStrLength(const char _kcMyString[], bool _bReset)
{
	static size_t iLongestStringLength = 0;

	if (_bReset == true) {
		iLongestStringLength = 0;
	}

	if (strlen(_kcMyString) > iLongestStringLength) {
		iLongestStringLength = strlen(_kcMyString);
	}

	return static_cast<int>(iLongestStringLength);
}
/**
*
* Adds an option to the current menu
*
* @author Bryce Booth
* @param Option String
* @param Option ID
* @param Reset default variables for new menu
*
*/
void AddMenuOption(const char _kcpOption[], int _iOptNum, bool _bReset)
{
	static int iStartingX = -1;
	static int iStartingY = -1;

	if (_bReset == true) {
		iStartingX = -1;
		iStartingY = -1;
	}

	if (iStartingX == -1 && iStartingY == -1) {
		GetCursorPosition( iStartingX , iStartingY );
	}

	SetCursorPosition( iStartingX + g_kiMenu_Indent_X , iStartingY + (_iOptNum * g_kiMenu_Opt_Spacing_Y) );
	cout << _kcpOption;
}
/**
*
* Display what option on the menu the user is looking at
*
* @author Bryce Booth
* @param Starting X coordinates of the top-left of the menu
* @param Starting Y coordinates of the top-left of the menu
* @param The Option number ID the user has navigated to
* @param Reset default variables for new menu
*
*/
void SelectMenuOption(int _iStartingX, int _iStartingY, int _iOptionNum, bool _bReset)
{
	static int iLastOptionNum = -1;
	
	if (_bReset == true) {
		iLastOptionNum = -1;
	}

	int iCoordX = 0, iCoordY = 0;
	iCoordX = _iStartingX + g_kiMenu_Indent_X - g_kiMenu_Sel_Deindent;
	iCoordY = _iStartingY + (_iOptionNum * g_kiMenu_Opt_Spacing_Y);

	SetCursorPosition( iCoordX , iCoordY );

	OBJECT tToSet;

	tToSet = GetObject(tMENU_SELECT);
	SetColour(tToSet);
	cout << tToSet.Char;

	if (iLastOptionNum != -1)
	{
		iCoordX = _iStartingX + g_kiMenu_Indent_X - g_kiMenu_Sel_Deindent;
		iCoordY = _iStartingY + (iLastOptionNum * g_kiMenu_Opt_Spacing_Y);

		SetCursorPosition( iCoordX , iCoordY );

		tToSet = GetObject(tCONT_BODY);
		SetColour(tToSet);
		cout << tToSet.Char;
	}

	iLastOptionNum = _iOptionNum;
}
/**
*
* Allow user to navigate up and down the menu and select an option
*
* @author Bryce Booth
* @param Starting X coordinates of the top-left of the menu
* @param Starting Y coordinates of the top-left of the menu
* @param The number of options in the menu
*
*/
int  GetMenuOptionSelection(int _iStartingX, int _iStartingY, int _iNumOptions)
{
	char ucAcceptKeys[] = { eARROW_UP, eARROW_DOWN, eSPACEBAR, '\0' };
	int  iOptionNumber = 0;
	char ucAction = 0;

	SelectMenuOption( _iStartingX , _iStartingY , iOptionNumber , true );

	while ( (ucAction = GetInput(ucAcceptKeys)) !=  eSPACEBAR)
	{
		if (ucAction == eARROW_UP && iOptionNumber > 0) {
			-- iOptionNumber;
		}
		else if (ucAction == eARROW_DOWN && iOptionNumber < (_iNumOptions - 1)) {
			++ iOptionNumber;
			
		}
		else {
			continue;
		}

		PlayGameSound(eSND_TICK);
		SelectMenuOption( _iStartingX , _iStartingY , iOptionNumber );
	}
	
	PlayGameSound(eSND_SELECT);
	return iOptionNumber;
}
/*Game Menus*/
/**
*
* Allows the user to input their name for the game
*
* @author Bryce Booth
*
*/
void DisplayGetPlayerNameMenu()
{
	CreateContainer( "Player Name" , 44 , 3 , -1 , -1 );

	char cPlayerName[(g_kiPlayer_Name_MaxLength + 1)];
	int bResult = false;

	cout << "Please enter your name: ";

	HideCursor(false);

	int iTempX = 0, iTempY = 0;
	int iCursorX = 0, iCursorY = 0;

	GetCursorPosition( iTempX , iTempY );

	iCursorX = iTempX - 6;
	iCursorY = iTempY + 2;

	SetCursorPosition( iCursorX , iCursorY );

	cout << "Press Enter to continue...";

	SetCursorPosition( iTempX , iTempY );
	cin.getline( cPlayerName , g_kiPlayer_Name_MaxLength , '\n' );

	HideCursor(true);

	int iPlayerNameLength = 0;
	for (int I = 0; cPlayerName[I] != 0; ++I ) {
		++ iPlayerNameLength;
	}

	g_cPlayer_Name = new char[iPlayerNameLength + 1];

	if (g_cPlayer_Name == 0) {
		cout << "Your Computer Is Out Of Memory. Game Error." << endl;
		system("pause");
	}

	++ iPlayerNameLength;

	memcpy( g_cPlayer_Name , cPlayerName , iPlayerNameLength );

	g_cPlayer_Name_Length = iPlayerNameLength;

	RemoveLastContainer();
}
/**
*
* Displays the controls to the player
*
* @author Bryce Booth
*
*/
void DisplayControls(int _iControlType)
{
	int iStartX = 0, iStartY = 0;
	
	iStartX = g_kiShipBoard_TopLeft_X;
	iStartY = g_kiGameBoard_Top_Y + g_kiGameBoard_Magnified_Y + 2;

	int iTempX = 0, iTempY = 0;
	int iWidth = 70;
	
	if (_iControlType == 1) {
		CreateContainer( "Place Ship Controls" , iWidth , 6 , -1 , iStartY );
		GetCursorPosition( iTempX , iTempY );
		
		cout << "Move Ship Position: Up Arrow, Down Arrow, Left Arrow, Right Arrow";
		SetCursorPosition( iTempX , iTempY + 2 );
		cout << "Rotate Ship: R";
		SetCursorPosition( iTempX , iTempY + 4 );
		cout << "Accept Ship Position: Spacebar";
	}

	if (_iControlType == 2) {
		CreateContainer( "Randomly Place Ships Controls" , iWidth , 4 , -1 , iStartY );
		GetCursorPosition( iTempX , iTempY );
		
		cout << "Generate New Ship Positions: Up Arrow, Down Arrow";
		SetCursorPosition( iTempX , iTempY + 2 );
		cout << "Accept Ship Positions: Spacebar";
	}

	if (_iControlType == 3) {
		CreateContainer( "Attack Controls" , iWidth , 6 , -1 , iStartY );
		GetCursorPosition( iTempX , iTempY );
		
		cout << "Move Cursor: Up Arrow, Down Arrow, Left Arrow, Right Arrow";
		SetCursorPosition( iTempX , iTempY + 2 );
		cout << "Accept Coordinates To Attack: Spacebar";
		SetCursorPosition( iTempX , iTempY + 4 );
		cout << "Game Menu: Esc";
	}
}




/**
*
* Displays the briefing of the game to the player
*
* @author Bryce Booth
*
*/
void DisplayBriefing()
{
	char cBrief[3][512];
	
	memcpy( cBrief[0] , g_kcBriefPart1 , sizeof(g_kcBriefPart1) / g_iSizeOfChar );
	memcpy( cBrief[1] , g_kcBriefPart2 , sizeof(g_kcBriefPart2) / g_iSizeOfChar );
	memcpy( cBrief[2] , g_kcBriefPart3 , sizeof(g_kcBriefPart3) / g_iSizeOfChar );

	int iStartX = 0, iStartY = 0;

	int iContainerLength = 0, iBriefLength = 0, iCurrentY = 0, iLines = 0;
	int iLetterPauseTimer = 0, iNewLinePauseTimer = 0;

	OBJECT tToSet = {0,0,0,0};

	iContainerLength = 73;
	
	for (int I = 0; I < 3; ++ I)
	{
		iLetterPauseTimer  = 20;
		iNewLinePauseTimer = 800;

		if (I == 0) {
			iLines = 9;
		}
		else if (I == 1) {
			iLines = 8;
		}
		else if (I == 2) {
			iLines = 10;
		}
		CreateContainer( "Briefing" , iContainerLength , iLines , -1 , -1 );

		GetCursorPosition( iStartX , iStartY );

		iBriefLength = static_cast<int>(strlen(cBrief[I]));
		iCurrentY = iStartY;

		for (int iChar = 0; iChar < iBriefLength; ++ iChar)
		{
			if (cBrief[I][iChar] == '#') {
				SetCursorPosition( iStartX , ++ iCurrentY );

				if (cBrief[I][iChar + 1] == '#') {
					Sleep(iNewLinePauseTimer);
				}

				continue;
			}

			//Skip Brief//
			if (_kbhit() != false) {
				iLetterPauseTimer  = 0;
				iNewLinePauseTimer = 0;
			}

			Sleep(iLetterPauseTimer);
			cout << cBrief[I][iChar];
		}

		SetCursorPosition( iStartX + iContainerLength - 28 , iCurrentY + 3 );

		cout << "Press Spacebar to continue...";
		GetInput( "" , eSPACEBAR );

		RemoveLastContainer();
	}
}
/**
*
* Displays the option menu to the user to change game settings
*
* @author Bryce Booth
*
*/
void DisplayOptionsMenu()
{
	int  iMenuOptionsOpt = 0, iMenuCompAiOpt = 0, iMenuSoundOpt = 0;
	bool bBackToMainMenu = false;

	do
	{
		iMenuOptionsOpt = CreateMenu( "Options" , 7 , -1 , 3 , "Computer Speed" , "Sound" , "Back" );

		if (iMenuOptionsOpt == eCOMP_AI)
		{
			iMenuCompAiOpt = CreateMenu( "Computer Speed" , 7 , -1 , 3 , "Normal" , "Instant" , "Back" );
			if (iMenuCompAiOpt == eCOMP_NORM) {
				g_bComputerSpeedNorm = true;
			}
			else if (iMenuCompAiOpt == eCOMP_FAST) {
				g_bComputerSpeedNorm = false;
			}

			if (iMenuCompAiOpt == eCOMP_NORM || iMenuCompAiOpt == eCOMP_FAST)
			{
				if (g_bComputerSpeedNorm == true) {
					DisplayNotification("Computer Speed Set To Normal!");
				}
				else {
					DisplayNotification("Computer Speed Set To Instant!");
				}
			}
		}
		else if (iMenuOptionsOpt == eSOUND)
		{
			iMenuSoundOpt = CreateMenu( "Sound" , 7 , -1 , 3 , "On" , "Off" , "Back" );
			if (iMenuSoundOpt == eSOND_ON) {
				g_bSoundOn = true;
			}
			else if (iMenuSoundOpt == eSOND_OFF) {
				g_bSoundOn = false;
			}

			if (iMenuSoundOpt == eSOND_ON || iMenuSoundOpt == eSOND_OFF)
			{
				if (g_bSoundOn == true) {
					DisplayNotification("Sound Has Been Turned On !");
				}
				else {
					DisplayNotification("Sound Has Been Turned Off!");
				}
			}
		}
		else {
			bBackToMainMenu = true;
		}
	}
	while (bBackToMainMenu == false);
}
/**
*
* Displays the menu to see if the user wants to manually or automatically add their ships
*
* @author Bryce Booth
*
*/
bool DisplayShipPositioningMenu()
{
	int  iMenuPositionOpt = 0;
	bool bBackToMainMenu = false;

	iMenuPositionOpt = CreateMenu( "How Do You Want To Position Your Fleet?" , -1 , -1 , 2 , "Let Me Position Each Ship" , "Let The Caption Of Each Ship Decide" );

	RemoveLastContainer();

	return (iMenuPositionOpt == 1);
}
/**
*
* Displays the menu for when the user is in a game
*
* @author Bryce Booth
*
*/
void DisplayInGameMenu()
{
	int  iMenuSelectedOpt = 0, iSubMenuSeletedOpt = 0;
	bool bExitMenu = true;

	do
	{
		bExitMenu = true;

		iMenuSelectedOpt = CreateMenu( "Menu" , -1 , -1 , 3 ,  "Resume" , "Options" , "Main Menu" );

		switch (iMenuSelectedOpt)
		{
		case eRESUME_GAME:
			break;
		case eIN_GAME_OPTS:
			ShowGameBoard( ePLAYER_HUMAN); //Refresh
			DisplayOptionsMenu();
			bExitMenu = false;
			break;
		case eIN_GAME_MAIN_MENU:
			iSubMenuSeletedOpt = CreateMenu( "Are You Sure?" , -1 , -1 , 2 ,  "No    " , "Yes" );

			if (iSubMenuSeletedOpt == 0) {
				bExitMenu = false;
			}
			else {
				DisplayMessage( "System Message" , "You will be taken to the main menu after#the current player finishes their turn.#");
				g_bQuitGame = true;
				bExitMenu = true;
			}
			break;
		}
		ShowGameBoard( ePLAYER_HUMAN); //Refresh
	}
	while (bExitMenu == false);
}

/*Notifications*/
/**
*
* Creates a container in the center of the screen with text in it
*
* @author Bryce Booth
* @param The string to go in the container
*
*/
void DisplayNotification(const char _kcNotification[])
{
	int iNotifLength = 0;
	
	iNotifLength = static_cast<int>(strlen(_kcNotification));

	CreateContainer( "" , iNotifLength , 1 , -1 , -1 );

	cout << _kcNotification;

	GetInput( "" , eSPACEBAR );

	RemoveLastContainer();
	PlayGameSound(eSND_SELECT);

	if (g_iCurrentPhase != eMAIN_MENU) {
		ShowGameBoard( ePLAYER_HUMAN ); //Refresh
	}
}
/**
*
* Creates a container in the center of the screen with a larger message in it
* Allows special text formating
*
* @author Bryce Booth
* @param The title of the container
* @param The string to go in the container
*
*/
void DisplayMessage(const char _kcTitle[], const char _kcMessage[])
{
	int iLongestStrLength = 0, iCurrentStrLength = 0, iNumLines = 0;

	int iMessageLength = static_cast<int>(strlen(_kcMessage));

	for (int I = 0; I < iMessageLength; ++ I)
	{
		if (_kcMessage[I] == '#') {

			++ iNumLines;

			if (iCurrentStrLength > iLongestStrLength) {
				iLongestStrLength = iCurrentStrLength;
			}
			iCurrentStrLength = 0;
		}

		++ iCurrentStrLength;
	}

	CreateContainer( _kcTitle , iLongestStrLength , ++ iNumLines , -1 , -1 );

	int iTempX = 0, iTempY = 0;
	GetCursorPosition( iTempX , iTempY );

	for (int I = 0; I < iMessageLength; ++ I)
	{
		if (_kcMessage[I] == '&' && _kcMessage[I + 1] == 'P' && _kcMessage[I + 2] == 'N') {
			cout << g_cPlayer_Name;
			I += 2;
			continue;
		}
		if (_kcMessage[I] == '#') {
			SetCursorPosition( iTempX , ++ iTempY );
			continue;
		}

		cout << _kcMessage[I];
	}

	GetInput( "" , eSPACEBAR );

	RemoveLastContainer();
	PlayGameSound(eSND_SELECT);

	if (g_iCurrentPhase != eMAIN_MENU)  {
		ShowGameBoard( ePLAYER_HUMAN ); //Refresh
	}
}
/**
*
* Asks user to press spacebar to get to the main menu
*
* @author Bryce Booth
*
*/
void DisplayPressSpaceToStart()
{
	bool bTextBlink = 1;

	do
	{
		CreateContainer( "" , 23, 1 , -1 , 53 );
		if (bTextBlink == 1) {
			cout << "Press Spacebar To Start";
		}

		Sleep(300);
		if (_kbhit() != false) {
			break;
		}
		Sleep(300);

		bTextBlink = (bTextBlink == 0) ? 1 : 0;
	}
	while (_kbhit() == false);

	PlayGameSound(eSND_SELECT);
	RemoveLastContainer();
}
/**
*
* Asks user to press spacebar to get to the main menu
*
* @author Bryce Booth
*
*/
void DisplayWelcomeMessage()
{
	int iContWidth = 0;

	iContWidth = g_cPlayer_Name_Length + 17; //+ Legnth of "Welcome Admiral, "

	CreateContainer( "U.S Command" , iContWidth , 2 , -1  , -1 );

	cout << "Welcome Admiral, " << g_cPlayer_Name;

	PlayGameSound(eSND_TICK);
	GetInput( "" , eSPACEBAR );
}


/*Game General*/
/**
*
* Clears the player game board
*
* @author Bryce Booth
* @param The ID of the player to have his board cleared
* @param The ID of the board to be cleared
*
*/
void ClearPlayerBoard(int _iPlayerID, bool _bBoard)
{
	for (int iY = 0; iY < g_kiGameBoard_Y; ++ iY)
	{
		for (int iX = 0; iX < g_kiGameBoard_X; ++ iX)
		{
			if (_bBoard == eBOARD_SHIPS) {
				g_iGameBoard[_iPlayerID][_bBoard][iX][iY] = tWATER.ID;
			}
			else if (_bBoard == eBOARD_ENEMY) {
				g_iGameBoard[_iPlayerID][_bBoard][iX][iY] = -1;
			}
		}
	}
}
/**
*
* Clears the player ship board
*
* @author Bryce Booth
* @param The ID of the player to have his board cleared
*
*/
void ClearShipBoard(int _iPlayerID)
{
	for (int iY = 0; iY < g_kiGameBoard_Y; ++ iY)
	{
		for (int iX = 0; iX < g_kiGameBoard_X; ++ iX)
		{
			g_iShipBoard[_iPlayerID][iX][iY] = -1;
		}
	}
}
/**
*
* Resets all needed game varaibles to start a new game
*
* @author Bryce Booth
*
*/
void ResetGameVariables()
{
	//Reset Random Seed//
	srand( static_cast<int>(time(0)) );
	
	g_Game_Winner = -1;

	//Reset Game Board Values//
	ClearPlayerBoard( ePLAYER_HUMAN , eBOARD_SHIPS );
	ClearPlayerBoard( ePLAYER_HUMAN , eBOARD_ENEMY );

	ClearPlayerBoard( ePLAYER_COMPUTER , eBOARD_SHIPS );
	ClearPlayerBoard( ePLAYER_COMPUTER , eBOARD_ENEMY );

	//Reset Ship Board Values//
	ClearShipBoard( ePLAYER_HUMAN );
	ClearShipBoard( ePLAYER_COMPUTER );

	//Reset Players' Ships Health//
	memcpy( g_iPlayerShipsHealth[0] , g_kiShipLengths , (g_kiNumOfShips * g_iSizeOfInt) );
	memcpy( g_iPlayerShipsHealth[1] , g_kiShipLengths , (g_kiNumOfShips * g_iSizeOfInt) );

	//Reset Player Name//
	if (g_cPlayer_Name != 0) {
		delete[] g_cPlayer_Name;
	}
	g_cPlayer_Name = 0;

	g_bQuitGame = false;
}
/**
*
* Displays the gameboard
*
* @author Bryce Booth
* @param The ID of the player to have his board displayed
* @param Refresh only the ships on the board
* @param Refresh a selected board
*
*/
void ShowGameBoard(int _iPlayerID, bool _bRefreshBoatsOnly, int _iBoard)
{
	int  iStartX = 0 , iStartY = 0;
	bool bBoard = 0;

	iStartX = g_kiShipBoard_TopLeft_X;
	iStartY = g_kiGameBoard_Top_Y;

	OBJECT tToSet;

	int iCurrentX = 0, iCurrentY = 0;

	for (int iY = 0; iY < g_kiGameBoard_Y; ++ iY)
	{
		for (int MH=0; MH < g_kiGameBoard_Magnify_Y; ++MH)
		{
			bBoard = 0;

			SetCursorPosition( iStartX , iStartY );

			for (int iX = 0; iX < 20; ++ iX)
			{
				if (_iBoard == eBOARD_SHIPS && iX == 10) {
					break;
				}

				if (_iBoard == eBOARD_ENEMY && iX < 10) {
					iX = 10;
				}

				if (iX <= 10){
					tToSet = GetObject( tEMPTY ,  g_iGameBoard[_iPlayerID][eBOARD_SHIPS][iX][iY] );
				}
				else {
					tToSet = GetObject( tEMPTY , g_iGameBoard[_iPlayerID][eBOARD_ENEMY][iX - 10][iY] );
				}

				SetColour( tToSet );

				if (iX == 10)
				{
					SetCursorPosition( g_kiEnemyBoard_TopLeft_X , iStartY );
					bBoard = 1;
				}

				if (_bRefreshBoatsOnly == true)
				{
					if (tToSet.ID != tSHIP.ID && tToSet.ID != tHIT_SHIP.ID && tToSet.ID != tDESTROYED_SHIP.ID)
					{
						GetCursorPosition( iCurrentX , iCurrentY );
						SetCursorPosition( iCurrentX + g_kiGameBoard_Magnify_X , iStartY );

						continue;
					}
				}

				for (int MW = 0; MW < g_kiGameBoard_Magnify_X; ++MW)
				{
					cout << tToSet.Char;
				}
			}

			++ iStartY;
		}
	}
}
/**
*
* Highlights the players' ship on the screen
*
* @author Bryce Booth
* @param The ID of the player to have his ships highlighted
* @param Custom colour to make the ships highlight with
*
*/
void HighlightPlayerShips(int _iPlayerID, int _iColour)
{
	int iTempColour = 0;
	iTempColour = tSHIP.Char_Colour;

	tSHIP.Char_Colour = eL_GREEN;
	ShowGameBoard( _iPlayerID , true , eBOARD_SHIPS );

	Sleep(400);

	tSHIP.Char_Colour = iTempColour;
	ShowGameBoard( _iPlayerID , true , eBOARD_SHIPS );
}
/**
*
* Updates Gameboard with the position of the destoryed ship
*
* @author Bryce Booth
* @param The ID of the player whoes ship was destroyed
* @param The ID of the destoryed ship to search for
*
*/
void MarkShipAsDesroyed(int _iPlayerID, int _iShipID)
{
	int iDefenderID = (_iPlayerID == ePLAYER_HUMAN) ? ePLAYER_COMPUTER : ePLAYER_HUMAN;

	for ( int iY = 0; iY < g_kiGameBoard_Y; ++ iY )
	{
		for ( int iX = 0; iX < g_kiGameBoard_X; ++ iX )
		{
			if (g_iShipBoard[_iPlayerID][iX][iY] != _iShipID) {
				continue;
			}

			g_iGameBoard[_iPlayerID][eBOARD_SHIPS][iX][iY]  = tDESTROYED_SHIP.ID;
			g_iGameBoard[iDefenderID][eBOARD_ENEMY][iX][iY] = tDESTROYED_SHIP.ID;
		}
	}
}
/**
*
* Replaces a section of the game board with custom Objects without changing the gameboard values
*
* @author Bryce Booth
* @param The ID of the player for the Game Board
* @param The ID of the board
* @param X Coordinates on the board
* @param Y Coordinates on the board
* @param Orinetation of the Extension
* @param Object to set colour of section
* @param The length of the replacement
*
*/
void ReplaceGameBoardSection(int _iPlayerID, bool _bBoard, int _iX, int _iY, bool _bO, OBJECT _tToSet, int _iExtension)
{
	int iStartX = 0, iStartY = 0;
	
	iStartX = (_bBoard == eBOARD_SHIPS) ? g_kiShipBoard_TopLeft_X : g_kiEnemyBoard_TopLeft_X;
	iStartY = g_kiGameBoard_Top_Y;

	iStartX += _iX * g_kiGameBoard_Magnify_X; //Postion Cursor In Board
	iStartY += _iY * g_kiGameBoard_Magnify_Y; //Postion Cursor In Board

	int iExtensionX = 1, iExtensionY = 1;

	if (_bO == 0) {
		iExtensionX = _iExtension;
		iExtensionX -= ( (_iX + _iExtension) > g_kiGameBoard_X)  ? (_iX + _iExtension) - g_kiGameBoard_X  : 0;
	}
	else {
		iExtensionY = _iExtension;
		iExtensionY -= ( (_iY + _iExtension) > g_kiGameBoard_Y) ? (_iY + _iExtension) - g_kiGameBoard_Y : 0;
	}

	OBJECT tToSet;

	for (int iY = 0; iY < iExtensionY ; ++ iY)
	{
		for (int MH=0; MH < g_kiGameBoard_Magnify_Y; ++MH)
		{
			SetCursorPosition( iStartX , iStartY );

			for (int iX = 0; iX < iExtensionX; ++ iX)
			{
				if      (_bO == false && _tToSet.ID == 0) {
					tToSet = GetObject( tEMPTY , g_iGameBoard[_iPlayerID][_bBoard][_iX + iX][_iY] );
				}
				else if (_bO == true  && _tToSet.ID == 0) {
					tToSet = GetObject( tEMPTY , g_iGameBoard[_iPlayerID][_bBoard][_iX][_iY + iY] );
				}
				else {
					tToSet = GetObject(_tToSet);
				}

				SetColour( tToSet );

				for (int MW = 0; MW < g_kiGameBoard_Magnify_X; ++MW)
				{
					cout << tToSet.Char;
				}
			}

			++ iStartY;
		}
	}
}

/*Player Only Functions*/
/**
*
* Allows the player to select coordinates to attack
*
* @author Bryce Booth
*
*/
void BeginHumanTurn()
{
	int  iX = 0, iY = 0, iHitShipID = -1;
	bool bShipDestroyed = false;

	do
	{
		SelectCoordinate( eBOARD_ENEMY , iX , iY );
	}
	while (HasCoordinatesBeenAttacked( ePLAYER_HUMAN , iX , iY ) != false);

	AttackCoorinates( ePLAYER_HUMAN , iHitShipID , iX , iY , bShipDestroyed );

	ShowGameBoard( ePLAYER_HUMAN , true , eBOARD_ENEMY );
}
/**
*
* Allows the player to place their ships onto the game board
*
* @author Bryce Booth
*
*/
void BeginPlacingShips()
{
	int  iX = 0, iY = 0, iShipSize = 0;
	bool bO = false, FirstTime = true;

	for (int iShipID = 0; iShipID < g_kiNumOfShips; ++ iShipID)
	{
		FirstTime = true;
		iShipSize = g_kiShipLengths[iShipID];
		
		do
		{
			if (FirstTime != true) {
				PlayGameSound(eSND_ERROR);
			}
			FirstTime = false;

			SelectCoordinate( eBOARD_SHIPS , iX , iY , bO, iShipSize );
		}
		while ( IsShipPositionValid(  ePLAYER_HUMAN , iShipSize , iX , iY , bO ) != true );
	
		PlaceShip( ePLAYER_HUMAN , iShipSize , iShipID , iX , iY , bO );

		PlayGameSound( eSND_SELECT );

		if ( (iShipID + 1) != g_kiNumOfShips ) //For Looks
		{
			ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , iX , iY , bO , tCOORDCURSOR_SEL , g_kiShipLengths[iShipID] );
			Sleep(100);
			ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , iX , iY , bO , tEMPTY , iShipSize );
		}
	}
}
/**
*
* Allows the player to generate random positions for their ships
*
* @author Bryce Booth
*
*/
void BeginGeneratingShips()
{
	char GenerateKeys[] = { eARROW_UP , eARROW_DOWN , eSPACEBAR };
	bool FirstTime = false;

	do
	{
		if ( FirstTime ++ != false ) {
			PlayGameSound( eSND_LASER );
		}
		
		ClearPlayerBoard( ePLAYER_HUMAN , eBOARD_SHIPS );
		ClearShipBoard( ePLAYER_HUMAN );

		GenerateShipPositions( ePLAYER_HUMAN );
		ShowGameBoard( ePLAYER_HUMAN , false , eBOARD_SHIPS ); //Refresh GameBoard
	}
	while ( GetInput(GenerateKeys) != eSPACEBAR);

	PlayGameSound( eSND_SELECT );
}
/**
*
* Allows the player to select coordinates on a chosen board
*
* @author Bryce Booth
* @param The ID of the board to select coordinates on
* @param Chosen X Coordinates
* @param Chosen Y Coordinates
* @param Chosen Orientation
* @param Extension of how many coordinates to select
*
*/
void SelectCoordinate(bool _bBoard , int& _iX , int& _iY , bool& _bO, int _iExtension)
{
	static int PlayerLastCoords[2][2] = { { 5 , 4 } , { 5 , 4 } };

	int _iPlayerID = ePLAYER_HUMAN;

	char Keys[] = { eARROW_UP, eARROW_DOWN, eARROW_LEFT, eARROW_RIGHT, eSPACEBAR, 'r', '\0'};
	char Action = '\0';

	_iX = PlayerLastCoords[_bBoard][0];
	_iY = PlayerLastCoords[_bBoard][1];

	bool bFirstTime = true;

	do
	{
		if (bFirstTime != true && Action != 'r') {
			PlayGameSound(eSND_TICK);
		}
		bFirstTime = false;

		ReplaceGameBoardSection( _iPlayerID , _bBoard , _iX , _iY , _bO , tEMPTY , _iExtension );

		if      (Action == eARROW_UP    && _iY > 0 ) { // Up
			_iY -= 1;
		}
		else if (Action == eARROW_DOWN  && _iY < 9 ) { // Down
			_iY += 1;
		}
		else if (Action == eARROW_LEFT  && _iX > 0 ) { // Left
			_iX -= 1;
		}
		else if (Action == eARROW_RIGHT && _iX < 9 ) { // Right
			_iX += 1;
		}
		else if (Action == 'r' && _bBoard == 0) {  // Rotate
			_bO = (_bO == false) ? true : false;
			PlayGameSound(eSND_ROTATE);
		}

		ReplaceGameBoardSection( _iPlayerID , _bBoard , _iX , _iY , _bO , tCOORDCURSOR , _iExtension );
	}
	while ( (Action = GetInput(Keys)) != eSPACEBAR); // IF not space

	PlayerLastCoords[_bBoard][0] = _iX;
	PlayerLastCoords[_bBoard][1] = _iY;
}

/*Computer Only Functions*/
/**
*
* The computers brain
* Allows the computer to decide what move to make on given situation
*
* @author Bryce Booth
*
*/
void BeginComputerTurn()
{
	static int iTarget_ID  = -1; //Ship ID
	static int iTarget_Ori = -1; //Orientation, -1: Unknown
	static int iTarget_FirstHitCoords[2];
	static int iTarget_LastHitCoords[2];

	int  iX = 0, iY = 0, iHitShipID = -1;
	bool bIsShipDestroyed = false;

	// If computer has no target
	// Check if there is a hit ship
	// If there is a hit ship, set shit as target
	if (iTarget_ID == -1 && SearchForHitShip( iX , iY ) == true) {
		iTarget_ID = g_iShipBoard[ePLAYER_HUMAN][iX][iY];

		iTarget_FirstHitCoords[0] = iX;
		iTarget_FirstHitCoords[1] = iY;

		iTarget_LastHitCoords[0] = iX;
		iTarget_LastHitCoords[1] = iY;
	}

	// If computer has no target.
	// Attack random coordinates.
	// If coordinates was a ship then set the ship as a target.
	if (iTarget_ID == -1) {

		AttackRandomCoordinates(iHitShipID, iX , iY , bIsShipDestroyed );
		
		if (bIsShipDestroyed == true) {
			return;
		}

		if (iHitShipID >= 0)
		{
			iTarget_ID  = iHitShipID;
			iTarget_Ori = -1;

			iTarget_FirstHitCoords[0] = iX;
			iTarget_FirstHitCoords[1] = iY;

			iTarget_LastHitCoords[0] = iX;
			iTarget_LastHitCoords[1] = iY;
		}

		return;
	}

	iX = iTarget_LastHitCoords[0];
	iY = iTarget_LastHitCoords[1];

	// If the computer does not know the targets orientation
	// Attack coordinates around last know position of target
	// If coordinates attack hit another part of the same shit
	// Calculate the targets orientation
	if (iTarget_Ori == -1) {

		AttackRandomSurroundingCoordinates( iHitShipID , iX , iY , bIsShipDestroyed );

		if (iHitShipID != iTarget_ID) {
			return;
		}

		if (bIsShipDestroyed == true) {
			iTarget_ID  = -1;
			iTarget_Ori = -1;
		}

		if (iTarget_FirstHitCoords[0] != iX) {
			iTarget_Ori = 0;
		}
		else if (iTarget_FirstHitCoords[1] != iY) {
			iTarget_Ori = 1;
		}

		iTarget_LastHitCoords[0] = iX;
		iTarget_LastHitCoords[1] = iY;

		return;
	}

	// If the computer has a target and knows its orientation
	// Search and destroy the rest of it!
	bool bFunctionResult = false;
	
	if (iTarget_Ori == 0) {
		bFunctionResult = AttackRandomHorizontalCoordinates( iHitShipID, iX , iY , bIsShipDestroyed );
	}
	else {
		bFunctionResult = AttackRandomVerticalCoordinates( iHitShipID, iX , iY  , bIsShipDestroyed );
	}

	if (bFunctionResult == false) {
		iTarget_LastHitCoords[iTarget_Ori] = iTarget_FirstHitCoords[iTarget_Ori];
		BeginComputerTurn();
		return;
	}

	if (bIsShipDestroyed == true) {
		iTarget_ID  = -1;
		iTarget_Ori = -1;
	}

	if (iHitShipID != iTarget_ID) {
		iTarget_LastHitCoords[iTarget_Ori] = iTarget_FirstHitCoords[iTarget_Ori];
		return;
	}

	iTarget_LastHitCoords[iTarget_Ori] = (iTarget_Ori == 0) ? iX : iY;
}
/**
*
* Searches the enemy board to see if there is a stray hit ship
*
* @author Bryce Booth
* @param X Coordinate Of detected ship
* @param Y Coordinate Of detected ship
*
*/
bool SearchForHitShip(int& _iShipX, int& _iShipY)
{
	for (int iY = 0; iY < g_kiGameBoard_Y; ++ iY)
	{
		for (int iX = 0; iX < g_kiGameBoard_X; ++ iX )
		{
			if (g_iGameBoard[ePLAYER_HUMAN][eBOARD_SHIPS][iX][iY] == tHIT_SHIP.ID) {
				_iShipX = iX;
				_iShipY = iY;
				return true;
			}
		}
	}

	return false;
}
/**
*
* Makes computer to attack random coordinates on gameboard that have not been already attacked
*
* @author Bryce Booth
* @param ID of Ship if it hit one
* @param X Coordinate of Ship if it hit one
* @param Y Coordinate of Ship if it hit one
* @param If the ship was destoyed due to that attack
*
*/
void AttackRandomCoordinates(int& _iHitShipID, int& _iShipPosX, int& _iShipPosY, bool& _bIsShipDestoyed)
{	
	static int iLastAttackedCoords[2] = { 5 , 4 };

	int iX = 0, iY = 0;
	int iNumOfAttempts = 0;

	do
	{
		//Computer has spent more then 2 attempts trying to find a target
		//Force next coordinate search to be successful
		if (iNumOfAttempts ++ == 2)
		{
			do
			{
				iX = GenerateRandomNumber( 0 , g_kiGameBoard_X  );
				iY = GenerateRandomNumber( 0 , g_kiGameBoard_Y );
			}
			while ( HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) != false );
		}
		else
		{
			iX = GenerateRandomNumber( 0 , g_kiGameBoard_X  );
			iY = GenerateRandomNumber( 0 , g_kiGameBoard_Y );
		}

		PlayCoordinateAnimation( iLastAttackedCoords[0] , iLastAttackedCoords[1] , iX , iY );

		iLastAttackedCoords[0] = iX;
		iLastAttackedCoords[1] = iY;
	}
	while ( HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) != false );

	AttackCoorinates( ePLAYER_COMPUTER , _iHitShipID , iX , iY , _bIsShipDestoyed );

	_iShipPosX = iX;
	_iShipPosY = iY;
}
/**
*
* Attacks random coordinates around given X , Y coordinates in attempt to find another part of the last hit ship to find its orientation
*
* @author Bryce Booth
* @param ID of the ship for the computers target
* @param X Coordinate of the last hit position of the target ship
* @param Y Coordinate of the last hit position of the target ship
* @param If the ship was destoyed due to that attack
*
*/
void AttackRandomSurroundingCoordinates(int& _iTargetShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed)
{
	int iX = 0;
	int iY = 0;
	int iDirection = 0; // 0: Up, 1: Right, 2: Down 3: LefHitt

	do
	{
		iDirection = GenerateRandomNumber( 0 , 4 );

		iX = _iLastHitPosX;
		iY = _iLastHitPosY;

		if (iDirection == 0) {

			if (iY == 9) {
				continue;
			}

			iY = _iLastHitPosY + 1;
		}
		else if (iDirection == 1) {

			if (iX == 9) {
				continue;
			}

			iX = _iLastHitPosX + 1;
		}
		else if (iDirection == 2) {

			if (iY == 0) {
				continue;
			}

			iY = _iLastHitPosY - 1;
		}
		else if (iDirection == 3) {

			if (iX == 0) {
				continue;
			}

			iX = _iLastHitPosX - 1;
		}
	}
	while (HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) != false);

	AttackCoorinates( ePLAYER_COMPUTER , _iTargetShipID , iX , iY , _bIsShipDestoyed );

	_iLastHitPosX = iX;
	_iLastHitPosY = iY;
}
/**
*
* Attacks random horizontal coordinates around given X , Y coordinates in attempt to find another part of the target ship
*
* @author Bryce Booth
* @param ID of ship if it hit one
* @param X Coordinate of the last hit position of the target ship
* @param Y Coordinate of the last hit position of the target ship
* @param If the ship was destoyed due to that attack
*
*/
bool AttackRandomHorizontalCoordinates(int& _iHitShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed)
{
	int  iX = _iLastHitPosX, iY = _iLastHitPosY;
	bool bAttackDirection = false; //False: Left, True: Right

	bAttackDirection = (GenerateRandomNumber( 0 , 2 ) == 1);

	iX += (bAttackDirection == false) ? -1 : 1;
	iY =  _iLastHitPosY;

	if (iX > 9 || iX < 0) {
		return false;
	}

	if (HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) == true)
	{
		iX += (bAttackDirection == false) ? 2 : -2;
	}

	if (iX > 9 || iX < 0) {
		return false;
	}

	if (HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) == true)
	{
		return false;
	}

	PlayCoordinateAnimation( _iLastHitPosX , _iLastHitPosY , iX , iY );

	AttackCoorinates( ePLAYER_COMPUTER , _iHitShipID , iX , iY , _bIsShipDestoyed );

	_iLastHitPosX = iX;

	return true;
}
/**
*
* Attacks random vertical coordinates around given X , Y coordinates in attempt to find another part of the target ship
*
* @author Bryce Booth
* @param ID of ship if it hit one
* @param X Coordinate of the last hit position of the target ship
* @param Y Coordinate of the last hit position of the target ship
* @param If the ship was destoyed due to that attack
*
*/
bool AttackRandomVerticalCoordinates(int& _iHitShipID, int& _iLastHitPosX, int& _iLastHitPosY, bool& _bIsShipDestoyed)
{
	int  iX = _iLastHitPosX, iY = _iLastHitPosY;
	bool bAttackDirection = false; //False: Up, True: Down

	bAttackDirection = (GenerateRandomNumber( 0 , 2 ) == 1);

	iX =  _iLastHitPosX;
	iY += (bAttackDirection == false) ? -1 : 1;

	if (iY > 9 || iY < 0) {
		return false;
	}

	if (HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) == true)
	{
		iY += (bAttackDirection == false) ? 2 : -2;
	}

	if (iY > 9 || iY < 0) {
		return false;
	}

	if (HasCoordinatesBeenAttacked( ePLAYER_COMPUTER , iX , iY ) == true)
	{
		return false;
	}

	PlayCoordinateAnimation( _iLastHitPosX , _iLastHitPosY , iX , iY );

	AttackCoorinates( ePLAYER_COMPUTER , _iHitShipID , iX , iY , _bIsShipDestoyed );

	_iLastHitPosY = iY;

	return true;
}
/**
*
* Displays the computer actions in real time to the user
*
* @author Bryce Booth
* @param The starting/cuurent X coordinate
* @param The starting/cuurent Y coordinate
* @param The destination X coordinate
* @param The destination Y coordinate
*
*/
void PlayCoordinateAnimation(int _iStartX, int _iStartY, int _iDestX, int _iDestY)
{
	//ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , _iStartX , _iStartY , false , tCOORDCURSOR );

	int  iCurrentX = 0, iCurrentY = 0;
	bool bXorY = false; //False: X, True: Y

	iCurrentX = _iStartX;
	iCurrentY = _iStartY;

	while (true)
	{
		if (iCurrentX == _iDestX && iCurrentY == _iDestY) {
			break;
		}

		//bXorY = (GenerateRandomNumber( 0 , 2 ) == 1);

		if (iCurrentX != _iDestX) { // bXorY == true &&
			iCurrentX += (iCurrentX < _iDestX) ? 1 : -1;
		}
		else if (iCurrentY != _iDestY) { //bXorY == false &&
			iCurrentY += (iCurrentY < _iDestY) ? 1 : -1;
		}
		else {
			continue;
		}

		if (g_bComputerSpeedNorm == true) {
			ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , iCurrentX , iCurrentY , false , tCOORDCURSOR );
			Sleep(70);
			ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , iCurrentX , iCurrentY , false , tEMPTY );
		}
	}

	//ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , _iDestX, _iDestY , false , tCOORDCURSOR );
	//Sleep(100);
	//ReplaceGameBoardSection( ePLAYER_HUMAN , eBOARD_SHIPS , _iDestX ,_iDestY , false , tEMPTY );
}

/*Player & Computer Functions*/
/**
*
* Randomly generates positions for all the players' ships
*
* @author Bryce Booth
* @param The ID of the player to generate ships for
*
*/
void GenerateShipPositions(int _iPlayerID)
{
	int  iX = 0, iY = 0, iShipSize = 0;
	bool bO = false;

	for (int iShipID = 0; iShipID < g_kiNumOfShips; ++ iShipID)
	{
		iShipSize = g_kiShipLengths[iShipID];

		do
		{
			iX = GenerateRandomNumber( 0 , g_kiGameBoard_X  );
			iY = GenerateRandomNumber( 0 , g_kiGameBoard_Y );
			bO = (GenerateRandomNumber( 0 , 2 ) == 1);
		}
		while ( IsShipPositionValid( _iPlayerID , iShipSize , iX , iY , bO ) != true);

		PlaceShip( _iPlayerID , iShipSize , iShipID , iX , iY , bO );
	}
}
/**
*
* Places giving give onto the players board
*
* @author Bryce Booth
* @param The ID of the player to place the ship for
* @param The length of the ship to place
* @param The ID of the ship to place
* @param The X Coordinate of the ship to be placed
* @param The Y Coordinate of the ship to be placed
* @param The orientation of the ship to be placed
*
*/
void PlaceShip(int _iPlayerID, int _iShipSize, int _iShipID, int _iX, int _iY, bool _bO)
{
	if (_bO == false)
	{
		for (int I = _iX; I < (_iX + _iShipSize); ++ I)
		{
			g_iGameBoard[_iPlayerID][eBOARD_SHIPS][I][_iY] = tSHIP.ID;
			g_iShipBoard[_iPlayerID][I][_iY] = _iShipID;
		}
	}

	if (_bO == true)
	{
		for (int I = _iY; I < (_iY + _iShipSize); ++ I)
		{
			g_iGameBoard[_iPlayerID][eBOARD_SHIPS][_iX][I] = tSHIP.ID;
			g_iShipBoard[_iPlayerID][_iX][I] = _iShipID;
		}
	}
}
/**
*
* Attacks given coordinates for player
*
* @author Bryce Booth
* @param The ID of the player that is attacking
* @param The ID of the ship if one is hit
* @param The X Coordinate of the ship if one is hit
* @param The Y Coordinate of the ship if one is hit
* @param If that attack on the ship destroyed it
*
*/
bool AttackCoorinates(int _iPlayerID, int& _iHitShipID, int _iX , int _iY, bool& _bShipDestoryed)
{
	int iDefenderID = (_iPlayerID == ePLAYER_HUMAN) ? ePLAYER_COMPUTER : ePLAYER_HUMAN;

	if ( IsCoordinatesAShip( iDefenderID , _iX , _iY ) == true )
	{

		g_iGameBoard[_iPlayerID][eBOARD_ENEMY][_iX][_iY]  = tHIT_SHIP.ID;
		g_iGameBoard[iDefenderID][eBOARD_SHIPS][_iX][_iY] = tHIT_SHIP.ID;

		int iShipID;
		iShipID = g_iShipBoard[iDefenderID][_iX][_iY];
		g_iPlayerShipsHealth[iDefenderID][iShipID] -= 1;

		int iRandomSound = (GenerateRandomNumber( 0 , 2 ) == 0) ? eSND_SMLEXPLOSION1 : eSND_SMLEXPLOSION2;
		PlayGameSound(iRandomSound);

		if (g_iPlayerShipsHealth[iDefenderID][iShipID] == 0) {
			MarkShipAsDesroyed( iDefenderID , iShipID );
			_bShipDestoryed = true;
		}

		if (_iPlayerID == ePLAYER_HUMAN) {
			ShowGameBoard( ePLAYER_HUMAN , true , eBOARD_ENEMY);
		}
		else {
			ShowGameBoard( ePLAYER_HUMAN , true , eBOARD_SHIPS);
		}

		//Sleep(500);

		if (_bShipDestoryed == true) {
			//Sleep(300);
			PlayGameSound(eSND_LRGEXPLOSION);
			//Sleep(1500);
		}

		_iHitShipID = iShipID;
	}
	else
	{
		g_iGameBoard[_iPlayerID][eBOARD_ENEMY][_iX][_iY]  = tHIT_WATER.ID;
		g_iGameBoard[iDefenderID][eBOARD_SHIPS][_iX][_iY] = tHIT_WATER.ID;

		if (_iPlayerID == ePLAYER_HUMAN) {
			ShowGameBoard( ePLAYER_HUMAN , false , eBOARD_ENEMY );
		}
		else {
			ShowGameBoard( ePLAYER_HUMAN , false , eBOARD_SHIPS );
		}

		PlayGameSound(eSND_HITWATER);

		//Sleep(500);
	}

	return true;
}

/*Check Functions*/
/**
*
* Checks if the ship can be placed on that part of the board or not
*
* @author Bryce Booth
* @param The ID of the player that is trying to place the ship
* @param The length of the ship that is being placed
* @param The X Coordinate of the ship that is being placed
* @param The Y Coordinate of the ship that is being placed
* @param The orientation of the ship that is to be placed
*
*/
bool IsShipPositionValid(int _iPlayerID, int _iShipSize, int _iX, int _iY, bool _bO)
{
	if (_bO == 0) //Ship is horizontal
	{
		if ( (_iX + _iShipSize) > 10 ) // Part of the ship goes off the grid
		{
			return false;
		}
		
		for (int I = _iX; I < (_iX + _iShipSize); ++ I)
		{
			if (IsCoordinatesAShip(_iPlayerID, I, _iY) == true)
				return false;
		}
	}

	if (_bO == 1) //Ship is vertical
	{
		if (_iY + _iShipSize > 10) // Part of the ship goes off the grid
		{
			return false;
		}
		
		for (int I = _iY; I < (_iY + _iShipSize); ++ I)
		{
			if (IsCoordinatesAShip(_iPlayerID, _iX, I) == true)
				return false;
		}
	}

	return true;
}
/**
*
* Checks if the giving coordinates has a ship on it
*
* @author Bryce Booth
* @param The ID of the player that is being checked
* @param The X Coordinate of the ship
* @param The Y Coordinate of the ship
*
*/
bool IsCoordinatesAShip(int _iPlayerID, int _iX, int _iY)
{
	if (g_iGameBoard[_iPlayerID][eBOARD_SHIPS][_iX][_iY] == tSHIP.ID) {
		return true;
	}

	return false;
}
/**
*
* Checks if the given coordinates have been attacked or not
*
* @author Bryce Booth
* @param The ID of the player that is attacking
* @param The X Coordinate position of the attack
* @param The Y Coordinate position of the attack
*
*/
bool HasCoordinatesBeenAttacked(int _iPlayerID, int _iX, int _iY)
{
	if (g_iGameBoard[_iPlayerID][eBOARD_ENEMY][_iX][_iY] == tHIT_SHIP.ID) {
		return true;
	}

	if (g_iGameBoard[_iPlayerID][eBOARD_ENEMY][_iX][_iY] == tDESTROYED_SHIP.ID) {
		return true;
	}

	if (g_iGameBoard[_iPlayerID][eBOARD_ENEMY][_iX][_iY] == tHIT_WATER.ID) {
		return true;
	}

	return false;
}
/**
*
* Checks if a player has won the game
*
* @author Bryce Booth
*
*/
bool IsThereAWinner()
{
	bool bAllShipsAreDestroyed;

	for (int iPlayerID = 0; iPlayerID < 2; ++ iPlayerID)
	{
		bAllShipsAreDestroyed = true;

		for (int I = 0; I < g_kiNumOfShips; ++ I)
		{
			if (g_iPlayerShipsHealth[iPlayerID][I] != 0) {
				bAllShipsAreDestroyed = false;
			}
		}

		if (bAllShipsAreDestroyed == true) {
			g_Game_Winner = (iPlayerID != ePLAYER_HUMAN) ? ePLAYER_HUMAN : ePLAYER_COMPUTER;

			return true;
		}
	}

	return false;
}
/**
*
* Detects and fixes a known bug that could not be debugged in time, jeopardizing the Game Ship Date (Submit Date)
*
* @author Bryce Booth
*
*/
void CheckForBug()
{
	static bool bHasChecked = false;
	static bool bIsMeantToBe0 = false;

	if (bHasChecked == false)
	{
		if (g_iShipBoard[ePLAYER_COMPUTER][9][9] == 0) {
			bIsMeantToBe0 = true;
		}
		else {
			bIsMeantToBe0 = false;
		}
		bHasChecked = true;
	}

	if (bIsMeantToBe0 == false)
	{
		if (g_iShipBoard[ePLAYER_COMPUTER][9][9] == 0) {
			g_iShipBoard[ePLAYER_COMPUTER][9][9] = -1;
		}
	}
}




/**
*
* Puts together the intro background for the game
*
* @author Bryce Booth
*
*/
void SetupIntroBackGround()
{
	int iBuffer = g_kiWindow_X + 2;
	int iIndex = 0;

	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000000+++                                                                                                        " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000000++                                                                                                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000+++         999999  999    999  999999999  9999999    999999  999        999  999999                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000++++         999999   999  999   999999999  99999999   999999  999        999  999999                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000++           999       999999       999     999   999  999     999999  999999  999                            " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++           99999      9999        999     99999999   99999   99999999999999  99999                          " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++           99999      9999        999     9999999    99999   999  9999  999  99999                          " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000+++            999       999999       999     999 999    999     999        999  999                            " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000+++            999999   999  999      999     999  999   999999  999        999  999999                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++           999999  999    999     999     999   999  999999  999        999  999999                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                                                                                                           " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000+++                                                                     BATTLE SHIPS                         " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000+++                                                                                                          " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                                                                                                           " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                                                                                                           " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000++++                                                                                                          " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000+++                                                                                                          " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000+++                                   44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                                    44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                             11     44                                                  22222222222        " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++                             1111    44                                                 2222222222222       " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++                             1111    44                                                  22222222222        " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000++                              1111    44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000++                               1111    44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000++                               1111    44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000+++                       11      1111    44                                      22222222                       " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000++                      1111     1111    44                                     2222222222                      " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000++                     1111      11     44                                      22222222                       " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000++                      1111             44                      3                                              " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000+++                      1111             44                     33                                              " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000++                      11              44                    333                                              " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++                               11    44                   33333333333333              222222222222222222    " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000++                              1111   44                  333333333333333             22222222222222222222   " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                             1111   44                 3333333333333333              222222222222222222    " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000000++                 11         1111   44                  333333333333333                                    " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000000++                1111        1111   44                   33333333333333                                    " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000000++                1111        1111   44                    333                                              " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000000++                1111         11    44                     33                  22222222222                 " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000++                 1111               44                      3                 2222222222222                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000000++                 1111               44                                         22222222222                 " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000+++                 1111      11       44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000000++                  1111     1111      44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000000+++                   11      1111      44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000000+++                            1111      44                                              222222222222222        " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000++++                            1111      44                                             22222222222222222       " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000000+++                             1111      44                                              222222222222222        " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000+++                              1111      44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000++                                11       44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000+++                                         44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000++                                          44                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000++        ++++                                                                                                     " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000+++       +++0+++                                                                                                   " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000+++     +++00000++                                                                                                  " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000+++   +++00000000++                                                                                                 " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000+++  ++00000000000++                                                                                                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000++ ++0000000000000++                                                                                               " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000+++00000000000000++                                                                                               " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000++++0000000000000+                                                                                                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000++++++00000000000++                                                                                                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000+++   +++0000000++                                                                                                 " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "00000000+++      ++00000++                                                                                                  " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000++      ++++++++                                                                                                   " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "000000000+++                                                                                                                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000++                                                                                                                " );
	strcpy_s( g_cIntroductionBackGround[iIndex ++] , iBuffer , "0000000000+++                                                                                                              $" );
}
/**
*
* Displays the intro background, or sections of it
*
* @author Bryce Booth
* @Param The start X coordinate to start displaying from
* @Param The start Y coordinate to start displaying from
* @Param The width of the section to display
* @Param The height of the section to display
*
*/
void DisplayIntroBackGround(int _iStartX, int _iStartY, int _iWidth, int _iHeight)
{
	unsigned char ucBlock = 219;
	int  iCurrentY = 0;
	SetCursorPosition( 0 , 0 );

	int iWdith = 0, iHeight = 0;

	if (_iWidth != 0 && _iHeight != 0) {
		iWdith  = _iWidth;
		iHeight = _iHeight;
	}
	else {
		iWdith  = g_kiWindow_X;
		iHeight = g_kiWindow_Y;
	}

	for (int iY = 0; iY < iHeight; ++ iY)
	{
		SetCursorPosition( _iStartX , _iStartY + iY );

		for (int iX = 0; iX < iWdith; ++ iX)
		{
			if (g_cIntroductionBackGround[iY + _iStartY][iX + _iStartX] == '$') {
				break;
			}

			switch (g_cIntroductionBackGround[iY + _iStartY][iX + _iStartX])
			{
			case '0':
				SetColour( tEMPTY , eD_GREEN);
				break;
			case '+':
				SetColour( tEMPTY , eL_BLUE);
				break;
			case '1':
				SetColour( tEMPTY , eL_GREEN);
				break;
			case '2':
				SetColour( tEMPTY , eD_GRAY);
				break;
			case '3':
				SetColour( tEMPTY , eL_RED);
				break;
			case '4':
				SetColour( tEMPTY , eYELLOW);
				break;
			case '9':
				SetColour( tEMPTY , eWHITE);
				break;
			case ' ':
				SetColour( tEMPTY , eWHITE , eD_BLUE );
				cout << ' ';
				continue;
				break;
			default:
				SetColour( tEMPTY , eWHITE , eD_BLUE );
				cout << g_cIntroductionBackGround[iY + _iStartY][iX + _iStartX];
				continue;
				break;
			}

			cout << ucBlock;
		}
	}
}