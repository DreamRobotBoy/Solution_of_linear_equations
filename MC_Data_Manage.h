#ifndef _MC_DATA_MANAGE_H_
#define _MC_DATA_MANAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef double FP64;
/********************************************************************************************
/********************************************************************************************
/********************************************************************************************
/************************** 数据链表矩阵基本算法 *******************************************
/********************************************************************************************
/********************************************************************************************
********************************************************************************************/
//多维数据链表矩阵
typedef struct Matrix
{
	FP64 fData;
	struct Matrix *pNextData;
}MC_Matrix_t;


/********************************************************************************************
函数功能：创建数据链表矩阵
@Param Param1:
@Param Param2:
@Param Param3:
返回值
********************************************************************************************/
MC_Matrix_t *MC_MatrixCreate();

/********************************************************************************************
函数功能：打印数据链表矩阵
@Param Param1:
@Param Param2:
@Param Param3:
返回值
********************************************************************************************/
void MC_MatrixPrint(MC_Matrix_t *pMatrix, uint16_t uiDimension);

/********************************************************************************************
函数功能：清除数据链表矩阵
@Param Param1:
@Param Param2:
@Param Param3:
返回值
********************************************************************************************/
void MC_MatrixClear(MC_Matrix_t *pMatrix);

/********************************************************************************************
函数功能：向数据链表矩阵添加数据
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0成功添加 1添加失败
********************************************************************************************/
uint8_t MC_MatrixAddData(MC_Matrix_t *pMatrix, FP64 fData);

/********************************************************************************************
函数功能：数据链表矩阵删除指定index链表
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0删除成功，1删除失败
********************************************************************************************/
uint8_t MC_MatrixDeleteIndex(MC_Matrix_t **pMatrix, uint16_t index);

/********************************************************************************************
函数功能：数据链表矩阵插入指定index链表
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0删除成功，1删除失败
********************************************************************************************/
uint8_t MC_MatrixInsertIndex(MC_Matrix_t *pMatrix, uint16_t index,FP64 fData);

/********************************************************************************************
函数功能：数据链表查找指定系数
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0删除成功，1删除失败
********************************************************************************************/
FP64 MC_MatrixCoeffIndex(MC_Matrix_t *pMatrix, uint16_t i, uint16_t j, uint16_t uiDimension);

/********************************************************************************************
函数功能：数据链表矩阵选主元
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0删除成功，1删除失败
********************************************************************************************/
uint8_t MC_MatrixSelectPivot(MC_Matrix_t **pMatrix,FP64 pValue[], uint16_t uiDimension);

/********************************************************************************************
函数功能：数据链表矩阵//第j行-第i行*第j行首系数/第i行首系数
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0成功，1失败
********************************************************************************************/
uint8_t MC_MatrixCalElim(MC_Matrix_t **pMatrix, FP64 pValue[], uint16_t i, uint16_t j, uint16_t uiDimension);

/********************************************************************************************
函数功能：数据链表矩阵//第j行-第i行*第j行首系数/第i行首系数
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0成功，1失败
********************************************************************************************/
uint8_t MC_MatrixCalBetterElim(MC_Matrix_t **pMatrix, FP64 pValue[], uint16_t i, uint16_t j, uint16_t uiDimension);


/********************************************************************************************
函数功能：数据链表矩阵消去运算
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0成功，1失败
********************************************************************************************/
uint8_t MC_MatrixElimination(MC_Matrix_t **pMatrix, FP64 pValue[], uint16_t uiDimension);


/********************************************************************************************
函数功能：数据链表矩阵求根运算
@Param Param1:
@Param Param2:
@Param Param3:
返回值 0成功，1失败
********************************************************************************************/
uint8_t MC_MatrixInverseCal(MC_Matrix_t *pMatrix, FP64 pValue[], FP64 pRoot[], uint16_t uiDimension);

#endif