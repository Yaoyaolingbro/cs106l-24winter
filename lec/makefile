# 设置默认的编译器
CXX = g++
# 设置默认的标准
STD = -std=c++17
# 设置编译选项
CXXFLAGS = -Wall -Wextra $(STD)

# 定义一个变量来接收命令行参数
SOURCE_FILE = $(firstword $(MAKECMDGOALS))

all = $(SOURCE_FILE) clean

$(SOURCE_FILE): $(SOURCE_FILE).cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "Compile $@ done!"
	./$@

# 清楚当前文件夹下所有的可执行文件
clean:
	rm -f $(SOURCE_FILE)