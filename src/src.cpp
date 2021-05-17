#include <iostream>
#include <thread>

class State
{
public:

	//仮想関数:派生クラスで再定義が出来る関数
	virtual void id()
	{
	}
};

//Credit:派生クラス,State:基底クラス
class Credit :public State
{
public:

	//idを再定義
	virtual void id()
	{
		std::cout << "credit\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class Title :public State
{
public:

	virtual void id()
	{
		std::cout << "title\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class Opening :public State
{
public:

	virtual void id()
	{
		std::cout << "opening\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};

class Demo :public State
{
public:
	virtual void id()
	{
		std::cout << "demo\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};

int main()
{
	/*
	それぞれのクラスのオブジェクトを作成させ、
	その中にあるidという関数を呼び出す。
	仮想関数を用いていることにより、
	派生クラスで再定義が出来るので、
	同じ関数名を使い、
	クラスで名前を区別する。
	whileの中は無限ループ(true)にしてあげる。
	*/

	Credit credit;
	Title title;
	Opening opening;
	Demo demo;

	do
	{
		credit.id();
		title.id();
		opening.id();
		demo.id();
	} while (true);
}