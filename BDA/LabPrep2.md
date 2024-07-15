# HBASE
## start all
`StartCDH.sh`
## JPS
`jps`
## hbase shell
`hbase shell`
`list`
`version`
## Create table
```hbase
CREATE 'name_space:table_name', 'column_family’
hbase(main):011:0> create 'newtbl','knowledge'
hbase(main):011:0>describe 'newtbl'
hbase(main):011:0>status
```
## Put/Insert command
```
put '<name_space:table_name>', '<row_key>' '<cf:column_name>', '<value>'
```
```
put 'newtbl','r1','knowledge:sports','cricket'
put 'newtbl','r1','knowledge:science','chemistry'
```
### Scan
```
scan 'newtbl'
```
### To retrieve only the row1 data
```
get 'newtbl', 'r1'
```
### Disable
```
disable 'newtbl'
```
### Verification
```
scan 'newtbl'
```
### is_disabled
```
is_disabled 'table name'
```
```
is_disabled 'newtbl'
```
### disable_all
```
disable_all 'r.*'
```
## Enabling a Table using HBase Shell
```
enable ‘newtbl’
```
### describe
```
describe 'table name'
```
# Hive
- Hive Data Def lang cmds
## Create
```
CREATE DATABASE|SCHEMA [IF NOT EXISTS] database_name
[COMMENT database_comment]
[LOCATION hdfs_path]
[WITH DBPROPERTIES (property_name=property_value, ...)];
```
`[] are optinal params`
```
CREATE DATABASE facultycse;
```
```
CREATE DATABASE IF NOT EXISTS employee COMMENT ‘this is employee database’ LOCATION ‘/user/hive/warehouse/hivedir/’ WITH DBPROPERTIES (‘creator’=‘Bhanu’, ‘date’=‘2020-12-07’);
```
## Show
```
SHOW DATABASES;
SHOW DATABASES LIKE  ‘*ee’;
SHOW DATABASES LIKE ‘fac*’;
```
## Describe
```
DESCRIBE DATABASE/SCHEMA [EXTENDED] db_name;
```
```
DESCRIBE DATABASE facultycse;
DESCRIBE DATABASE EXTENDED employee;
## Use
```
USE db_name;
```
## Drop
```
DROP (DATABASE|SCHEMA) [IF EXISTS] db_name [RESTRICT|CASCADE];
```
```
DROP DATABASE facultyece;
DROP DATABASE IF EXISTS facultycse CASCADE;
```
## Alter
```
ALTER (DATABASE|SCHEMA) db_name SET DBPROPERTIES (property_name=property_value, ...);
```
```
ALTER DATABASE employee SET DBPROPERTIES (‘creator’=‘Bhanu Prasad’, ‘date’=‘07-12-2020’);
```
```
ALTER (DATABASE|SCHEMA) database_name SET OWNER [USER|ROLE] user_or_role;
```
```
ALTER DATABASE employee SET OWNER USERclient;
```
```
ALTER DATABASE employee SET OWNER ROLE Admin;
```
