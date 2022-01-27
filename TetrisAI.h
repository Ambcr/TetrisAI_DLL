#ifndef _TETRISAI_H_
#define _TETRISAI_H_

#ifdef DLL_BUILD
#define DLL_EXPORT _declspec(dllexport)
#else
#define DLL_EXPORT _declspec(dllimport)
#endif
#include "TetrisAIInterface.h"


class TetrisAI:public TetrisAIInterface
{
public:
	TetrisAI(int width,int height);
	~TetrisAI();
	
	//获取AI对象
	//static TetrisAI* GetTetrisAIObject(int width,int height);
	static TetrisAIInterface* CreateInterface(int i, int j);

	//设置当前棋盘的状态(具体的传参，留待以后讨论)
	virtual void SetFieldCurrentStat(int** field);

	//设置当前形态状态
	virtual void SetShapeCurrentStat(TetrisType shape);

	//获取当前最佳路径
	virtual MaxScorePosition GetMaxScorePosition();

	//开启自动推理
	virtual void SetAutoRea(bool flag_auto_reasoning);

	//获取版本信息
	virtual std::string GetAIVersion();

private:
	int fieldWidth;
	int fieldHeight;
	int** fieldCurrent;
	int** mergeField;
	TetrisPoint currentShape[4];
	int tetrisFigures[7][4] =
	{
		1,3,5,7, // I
		2,4,5,7, // Z
		3,5,4,6, // S
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // O
	};

	//改变shape的状态至完全落地
	void ShapeDown();

	//还原shape至初始位置
	void ResetShapeToUp();

	//旋转shape
	void RotateShape();

	//检查板块的重心高度
	int GetLandingHeight();

	//设置shapedx
	bool SetShapeDX(int dx);

	//获取shape在棋盘上的动态范围
	TetrisShapeRange GetShapeRange();

	//check放置当前位置是否ok
	bool CheckIfOK(TetrisPoint* shape_here);

	//获取erodedPieceCellsMetric分数
	int GeterodedPieceCallsMetric(); 

	//获取boardRowTransitions分数
	int GetboardRowTransitions();

	//获取boardColTransitions分数
	int GetboardColTransitions();

	//获取boardBuriedHoles分数
	int GetboardBuriedHoles();

	//获取boardWells分数
	int GetboardWells();

	//获取总分
	int GetScore();

	//合并shape和field
	void DoMergeShapeAndField();

	//检查两个元素是否一致
	bool CheckABDiff(int a, int b);


	//检查两边是否是石头
	bool IsLeftRightStone(int i, int j);

	//连加函数
	int NumberPlusPlus(int number);

	//方块规整
	void ShapeRegular();

	//打印棋盘
	void PrintField();

	//打印合并棋盘
	void PrintMergeField();


};

//extern "C" DLL_EXPORT TetrisAI * GetTetrisAIObject(int i, int j);


#endif // !_TETRISAI_H_

