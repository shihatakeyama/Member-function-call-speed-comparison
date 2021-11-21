// CallSpeedComparison.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include <vector>

#include "stdafx.h"



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// �\���̒�`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

class Class0Virtual0
{
public:
	Class0Virtual0()
		:m_state0(0)
	{}

	void funcnv0(){
//		int i = 0;
		m_state0++;
	}

	int m_state0;
};

class Class0Virtual1
{
public:
	Class0Virtual1()
		: m_state0(0)
	{}

	void funcnv0(){
		int i = 0;
	}

	virtual void hoge0(){
		int i = 0;
	}

	int m_state0;
};

class Class1Virtual1
	:public Class0Virtual1
{
public:
	Class1Virtual1()
		:m_state1(0)
	{}

	void funcnv0(){
		int i = 0;
	}

	virtual void hoge0(){
		int i = 0;
	}

	int m_state1;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// �Ăяo�����x
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <time.h>
#define NUMBER_REPETITIONS		10000000
#define MAX_BUFSIZE				1024

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int loop;
	int i;
	std::vector<Class0Virtual0>	bufs(MAX_BUFSIZE);
	clock_t begin;

	printf("==== Call Speed Comparison START ====\n");
	printf("Number of loops\t: %d\n", NUMBER_REPETITIONS);

	{	// �z��[] �u���P�b�g �ɂ��Ăяo��
		Class0Virtual0 *p = &bufs[0];
		begin = clock();

		for (loop = 0; loop<NUMBER_REPETITIONS; loop++){
			for (i = 0; i < MAX_BUFSIZE; i++){
				p[i].funcnv0();
			}
		}
		printf("Array::[] bracket call time\t: %d ms\n", clock() - begin);
	
	}

	{	// vector::[] �u���P�b�g �ɂ��Ăяo��
		begin = clock();

		for (loop = 0; loop<NUMBER_REPETITIONS; loop++){
			for (i = 0; i < MAX_BUFSIZE; i++){
				bufs[i].funcnv0();
			}
		}
		printf("vector::[] bracket call time\t: %d ms\n", clock() - begin);

	}

	{	// for range �ɂ��Ăяo��
		begin = clock();

		for (loop = 0; loop < NUMBER_REPETITIONS; loop++){
			for (auto &e : bufs){
				e.funcnv0();
			}
		}
		printf("for range call time\t: %d ms\n", clock() - begin);
	}

	{	// vector::at() �ɂ��Ăяo��
		begin = clock();

		for (loop = 0; loop < NUMBER_REPETITIONS; loop++){
			for (i = 0; i < MAX_BUFSIZE; i++){
				bufs.at(i).funcnv0();
			}
		}
		printf("vector::at() call time\t: %d ms\n", clock() - begin);
	}

	printf("==== Call Speed Comparison END ====\n");

	getchar();

	return 0;
}

