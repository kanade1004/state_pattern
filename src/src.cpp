#include <iostream>
#include <thread>

class State
{
public:

	//仮想関数:派生クラスで再定義が出来る関数
	virtual void execute()
	{
	}
};

//Credit:派生クラス,State:基底クラス
class Credit :public State
{
public:

	//idを再定義
	void execute()
	{
		std::cout << "credit\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class Title :public State
{
public:

	void execute()
	{
		std::cout << "title\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class Opening :public State
{
public:

	void execute()
	{
		std::cout << "opening\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};

class Demo :public State
{
public:
	void execute()
	{
		std::cout << "demo\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};

class Content
{
public:

	void execute()
	{
		/*
		それぞれのクラスのオブジェクトを作成させ、
		その中にあるidという関数を呼び出す。
		仮想関数を用いていることにより、
		派生クラスで再定義が出来るので、
		同じ関数名を使い、
		クラスで名前を区別する。
		*/

		Credit credit;
		Title title;
		Opening opening;
		Demo demo;

		credit.execute();
		title.execute();
		opening.execute();
		demo.execute();
	}

};

int main()
{
	/*
	Contentクラスでそれぞれの関数を呼び出して保管する。
	保管したそのクラスの関数をさらに呼び出し、
	main関数の中を簡易化させました。
	whileの中は無限ループ(true)にしてあげる。
	*/
	Content content;

	do
	{
		content.execute();
	} while (true);
}