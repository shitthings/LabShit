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
## Hive Data Def lang cmds
### Create
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
### Show
```
SHOW DATABASES;
SHOW DATABASES LIKE  ‘*ee’;
SHOW DATABASES LIKE ‘fac*’;
```
### Describe
```
DESCRIBE DATABASE/SCHEMA [EXTENDED] db_name;
```
```
DESCRIBE DATABASE facultycse;
DESCRIBE DATABASE EXTENDED employee;
```
### Use
```
USE db_name;
```
### Drop
```
DROP (DATABASE|SCHEMA) [IF EXISTS] db_name [RESTRICT|CASCADE];
```
```
DROP DATABASE facultyece;
DROP DATABASE IF EXISTS facultycse CASCADE;
```
### Alter
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
## Hive2
### Create table
```
CREATE TABLE [IF NOT EXISTS] [db_name.] table_name	[(col_namedata_type [COMMENT col_comment], ... 	[COMMENT col_comment])] 
	[COMMENT table_comment] 
	[ROW FORMAT row_format] 
	[STORED AS file_format] 
	[LOCATION hdfs_path];
```
```
CREATE TABLE IF NOT EXISTS employee.emptable	(emp_id STRING COMMENT ‘This is Employee ID’, emp_name STRING COMMENT ‘This is Employee Name’, emp_sal FLOAT COMMENT ‘This is Employee Salary’) 
```
### Show
```
SHOW TABLES [IN database_name];
```
```
SHOW TABLES IN employee;
```
### Describe
```
DESCRIBE [EXTENDED|FORMATTED] [db_name.] table_name[.col_name ( [.field_name])];
```
```
DESCRIBE employee.emptable;
```
### Alter
```
ALTER TABLE table_name RENAME TO new_table_name;
ALTER TABLE table_name ADD COLUMNS (column1, column2) ;
ALTER TABLE table_name SET TBLPROPERTIES (‘property_key’=’property_new_value’);
```
```
ALTER TABLE employee.emptable RENAME TO employee.facultytable;
ALTER TABLE employee.facultytable ADD COLUMNS (emp_post string  COMMENT ‘This is employee post’, emp_age INT COMMENT ‘This is employee age’);
ALTER TABLE employee.facultytable  SET TBLPROPERTIES (‘table for’=’faculty data’);
```
### Drop
```
DROP TABLE [IF EXISTS] table_name [PURGE];
```
```
DROP TABLE IF EXISTS employee.emptable PURGE;
```
### Truncate
```
TRUNCATE TABLE table_name;
```
```
TRUNCATE TABLE employee.emptable;
```
## Hive3 DML
### Load
```
LOAD DATA [LOCAL] INPATH 'filepath' [OVERWRITE] INTO TABLE tablename [PARTITION (partcol1=val1, partcol2=val2 ...)];
```
```
LOAD DATA LOCAL INPATH ‘/home/cloudera/HiveDir/emptextdata' INTO TABLE employee.facultytable;
```
### Select
```
SELECT  *  FROM tablename;
```
```
SELECT * FROM employee.facultytable;
```
### insert
#### Insert into
```
INSERT INTO TABLE tablename [PARTITION (partcol1=val1, partcol2=val2 ...)] VALUES (col1value,col2value,…)
```
```
INSERT INTO TABLE employee.facultytable VALUES (4, ‘jessy’, 45000.00, ‘assocprof’, 40, ‘female’);
SELECT * FROM employee.facultytable;
```
#### Insert OverWrite
```
INSERT OVERWRITE TABLE tablename1 [PARTITION (partcol1=val1, ..) [IF NOT EXISTS]] select_statement FROM from_statement;
```
### Delete
```
DELETE FROM tablename [WHERE expression];
```
```
DELETE FROM employee.facultytable WHERE emp_age=38;
SELECT * FROM employee.facultytable;
```
### Update
```
UPDATE tablename SET column = value [, column = value ...] [WHERE expression];
```
```
UPDATE employee.facultytable SET emp_name = ‘mike tyson’ WHERE emp_age=45;
hive> SELECT * FROM employee.facultytable;
```
### Export
```
EXPORT TABLE tablename [PARTITION (part_column="value"[, ...])] TO 'export_target_path' [ FOR replication('eventid') ];
```
```
EXPORT TABLE employee.drivertable TO ‘/user/hive/warehouse’;
```
### Import
```
IMPORT [[EXTERNAL] TABLE new_or_original_tablename [PARTITION (part_column="value"[, ...])]] FROM 'source_path' [LOCATION 'import_target_path’];
```
```
IMPORT TABLE employee.importedtable FROM ‘/user/hive/warehouse’;
```
