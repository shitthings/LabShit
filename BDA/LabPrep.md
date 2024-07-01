# Section 1
## To start all Daemons in hadoop
```sh
start-all.sh
start-dfs.sh
start-yarn.sh
```
### Creating directory in Hadoop
```sh
hadoop fs -mkdir /BigData
```
### Creating an empty file with no data
```sh
hadoop fs -touchz hdfs:/Bigdata/Myfile
```
### Copying from local to HDFS
```sh
hadoop fs -copyFromLocal /home/workDir/fileName hdfs:/Bigdata
```
### Copying from HDFS to local
```sh
hadoop fs -copyToLocal hdfs:/Bigdata/Myfile /home/BigData
```
### Copying file from one Directory to other in hadoop
```sh
hadoop fs -cp hdfs:/Dir1/Myfile hdfs:/Dir2
```
### Moving file from one Directory to other in hadoop
```sh
hadoop fs -mv hdfs:/Dir1/Myfile hdfs:/Dir2
```
### Browsing a file in HDFS
```sh
hadoop fs -cat hdfs:/BigData/Myfile
```
### Counting of HDFS directories and files
```sh
hadoop fs -count hdfs:/
```
### Copying multiple files from local to hdfs
```sh
hadoop fs -put /home/BigData/Filename /home/BigData/Filename2 hdfs:/BigData
```
### Copying multiple files from HDFS to local
```sh
hadoop fs -get hdfs:/BigData/F1 hdfs:/BigData/F2 /home/BigData
```
### Moving local file system to HDFS file system
```sh
hadoop fs -moveFromLocal /home/workDir/fileName hdfs:/Bigdata
```
### Health check of HDFS
```sh
hadoop fs -ck /
```
### Browsing Dir/file/block info
```sh
hadoop fs -du hdfs:/
```
### Changing replication factor
```sh
hadoop fs -setrep 5 hdfs:/BigData/TextData
```
### Deleting a file from HDFS
```sh
hadoop fs -rm hdfs:/BigData/FileName
```
### Stoping all daemons
```sh
stop-all.sh
```
---
### Assuming environment variables are set as follows:
```sh
export JAVA_HOME=/usr/java/default
export PATH=${JAVA_HOME}/bin:${PATH}
export HADOOP_CLASSPATH=${JAVA_HOME}/lib/tools.jar
```
### Compile WordCount.java and create a jar:
```sh
bin/hadoop com.sun.tools.javac.Main WordCount.java
jar cf wc.jar WordCount*.class
```
### Assuming that:
```sh
/user/joe/wordcount/input - input directory in HDFS
/user/joe/wordcount/output - output directory in HDFS
```
### Sample text-files as input:
```sh
bin/hadoop fs -ls /user/joe/wordcount/input/ /user/joe/wordcount/input/file01 /user/joe/wordcount/input/file02
bin/hadoop fs -cat /user/joe/wordcount/input/file01
Hello World Bye World
bin/hadoop fs -cat /user/joe/wordcount/input/file02
Hello Hadoop Goodbye Hadoop
```
### Run the application:
```sh
bin/hadoop jar wc.jar WordCount /user/joe/wordcount/input /user/joe/wordcount/output
```
### Output:
```sh
bin/hadoop fs -cat /user/joe/wordcount/output/part-r-00000
```
```sh
Bye 1
Goodbye 1
Hadoop 2
Hello 2
World 2
```

