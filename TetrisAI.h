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
	
	//��ȡAI����
	//static TetrisAI* GetTetrisAIObject(int width,int height);
	static TetrisAIInterface* CreateInterface(int i, int j);

	//���õ�ǰ���̵�״̬(����Ĵ��Σ������Ժ�����)
	virtual void SetFieldCurrentStat(int** field);

	//���õ�ǰ��̬״̬
	virtual void SetShapeCurrentStat(TetrisType shape);

	//��ȡ��ǰ���·��
	virtual MaxScorePosition GetMaxScorePosition();

	//�����Զ�����
	virtual void SetAutoRea(bool flag_auto_reasoning);

	//��ȡ�汾��Ϣ
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

	//�ı�shape��״̬����ȫ���
	void ShapeDown();

	//��ԭshape����ʼλ��
	void ResetShapeToUp();

	//��תshape
	void RotateShape();

	//���������ĸ߶�
	int GetLandingHeight();

	//����shapedx
	bool SetShapeDX(int dx);

	//��ȡshape�������ϵĶ�̬��Χ
	TetrisShapeRange GetShapeRange();

	//check���õ�ǰλ���Ƿ�ok
	bool CheckIfOK(TetrisPoint* shape_here);

	//��ȡerodedPieceCellsMetric����
	int GeterodedPieceCallsMetric(); 

	//��ȡboardRowTransitions����
	int GetboardRowTransitions();

	//��ȡboardColTransitions����
	int GetboardColTransitions();

	//��ȡboardBuriedHoles����
	int GetboardBuriedHoles();

	//��ȡboardWells����
	int GetboardWells();

	//��ȡ�ܷ�
	int GetScore();

	//�ϲ�shape��field
	void DoMergeShapeAndField();

	//�������Ԫ���Ƿ�һ��
	bool CheckABDiff(int a, int b);


	//��������Ƿ���ʯͷ
	bool IsLeftRightStone(int i, int j);

	//���Ӻ���
	int NumberPlusPlus(int number);

	//�������
	void ShapeRegular();

	//��ӡ����
	void PrintField();

	//��ӡ�ϲ�����
	void PrintMergeField();


};

//extern "C" DLL_EXPORT TetrisAI * GetTetrisAIObject(int i, int j);


#endif // !_TETRISAI_H_

