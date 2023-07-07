// 定义 ANSI 转义序列
#define ANSI_ESCAPE "\033"


// 获得终端大小
struct winsize size()
{
	struct winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return size;
}

// 定义控制光标位置的函数
void setCursorPosition(int x, int y)
{
	cout << ANSI_ESCAPE << "[" << y << ";" << x << "H";
}


// 百分比计算器dp(<百分数>,<总体大小>);
int dp(int dpi, int altogether)
{
	// dpi 百分比
	// altogether 总体大小
	float percentage = 100;		// 固定百分比100%
	float pcr = dpi / percentage * altogether;	// 百分比计算结果
	return pcr;
}


// 获取当前光标位置
void getCursorPosition(int &row, int &col)
{
	// 发送 ANSI 转义序列 "\033[6n" 到标准输出
	std::cout << "\033[6n";

	// 读取光标位置的响应
	char escapeSequence[32];
	std::cin.getline(escapeSequence, 32, 'R');

	// 从响应中提取行和列信息
	sscanf(escapeSequence, "\033[%d;%d", &row, &col);
}



// 隐藏终端光标
void hideCursor()
{
	std::cout << "\033[?25l";
}

// 显示终端光标
void showCursor()
{
	std::cout << "\033[?25h";
}



// 读取用户输入字符
char getUserInput()
{
	struct termios oldt, newt;
	char input;

	tcgetattr(STDIN_FILENO, &oldt);	// 保存终端设置
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);	// 禁用规范模式和回显
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	input = std::cin.get();		// 从终端读取一个字符

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);	// 恢复终端设置

	return input;
}



// 判断当前选项Current options
int co(int a, int b)
{

	return (a == b ? 1 : 0);
}



// 计算字符串占位
int sp(string str)
{
	int ssp = 0;
	// 使用索引方式遍历字符串
	for (size_t i = 0; i < str.size();)
	{
		// 获取当前字符的字节数
		int byteCount = 1;
		if ((str[i] & 0b11100000) == 0b11000000)
			byteCount = 2;
		else if ((str[i] & 0b11110000) == 0b11100000)
			byteCount = 3;
		else if ((str[i] & 0b11111000) == 0b11110000)
			byteCount = 4;

		 switch (byteCount)
		{
		case 1:
			ssp += 1;
			break;
		case 2:
			ssp += 2;
			break;
		case 3:
			ssp += 2;
			break;
		case 4:
			ssp += 2;
			break;
		}

		// 移动索引到下一个字符
		i += byteCount;
	}

	return ssp;
}