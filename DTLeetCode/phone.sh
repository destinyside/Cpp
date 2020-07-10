#!/bin/bash

p=`cat file.txt`
for i in $p                #逐行读取文件内容并打印到屏幕
do
	echo $i
done
