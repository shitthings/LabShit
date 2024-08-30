## SET-1
### a. Create a web page with advanced layouts and positioning with CSS and HTML.
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>SNIST</title>
  <style>
    body { margin: 0; }
    .header, .column { padding: 20px; }
    .header { background: #f1f1f1; text-align: center; }
    .topnav { background: #333; overflow: hidden; }
    .topnav a { float: left; color: white; padding: 14px 16px; padding: 20px; text-decoration: none; }
    .topnav a:hover { background: #ddd; color: black; }
    .row { display: flex; }
    .column { flex: 1; }
  </style>
</head>
<body>
  <div class="header">
    <h1>SNIST</h1>
    <p>Sreenidhi Institute of Science and Technology</p>
  </div>
  <div class="topnav">
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Departmental Info</a>
  </div>
  <div class="row">
    <div class="column">
      <h2>College Info</h2>
      <p>Sreenidhi Institute of Science and Technology, established in 1997.</p>
    </div>
    <div class="column">
      <h2>Branches Info</h2>
      <p>CSE, IT, ECE, EEE, MECH, CIVIL...</p>
    </div>
    <div class="column">
      <h2>Address</h2>
      <p>Ghatkesar, Hyderabad</p>
    </div>
  </div>
</body>
</html>
```
### b. Create a simple calculator, which can perform the basic arithmetic operations.
```html
<!DOCTYPE html>
<html>
<head>
<body> <input type="number" name="first" id="first" step="any" /> <select id="ope">
        <option value="+">+</option>
        <option value="-">-</option>
        <option value="*">*</option>
        <option value="/">/</option>
    </select> <input type="number" name="second" id="second" step="any" /> <br /> <br /> <button onclick="cal()"> calculate</button> <input type="text" name="" id="res" readonly="" /> </body>
<script type="text/javascript">
    function cal(){
    var opr1 = document.getElementById('first').value;
    var opr2 = document.getElementById('second').value;
    var ope = document.getElementById('ope').value;
    if (ope == '+') {
    var res = parseInt(opr1) + parseInt(opr2);
    }
    if (ope == '-') {
    var res = parseInt(opr1) - parseInt(opr2);
    }
    if (ope == '*') {
    var res = parseInt(opr1) * parseInt(opr2);
    }
    if (ope == '/') {
    var res = parseInt(opr1) / parseInt(opr2);
    }
    document.getElementById('res').value = res;
    }
</script>
</html>
```
---

## SET-2
### Design a website with different methods of embedding CSS in a web page  a.Inline CSS  b.Internal CSS  c.External CSS
#### Inline CSS:
```html
<!DOCTYPE html>
<html>
<body>

<h1 style="color:blue;">A Blue Heading</h1>
<p style="color:red;">A red paragraph.</p>

</body>
</html>
```
#### Internal CSS:
```html
<!DOCTYPE html>
<html>
<head>
<style>
body {background-color: powderblue;}
h1 {color: blue;}
p {color: red;}
</style>
</head>
<body>
<h1>This is a heading</h1>
<p>This is a paragraph.</p>
</body>
</html>
```
#### Extenal CSS:
##### Html File:
```html
<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="ext.css">
</head>
<body>
    <h1>This is a heading</h1>
    <p>This is a paragraph.</p>
</body>
</html>
```
##### CSS File:
```css
body {
    background-color: powderblue;
   }
   h1 {
    color: blue;
   }
   p {
    color: red;
}
```
---

## SET-3
### a. Write an XML file which will display the Book information which includes the following
```xml
<!DOCTYPE bookstore SYSTEM "C:\wt\bookstore.dtd">
<bookstore>
	<book>
		<title>web programming</title>
		<author>chrisbates</author>
		<ISBN>123-456-789</ISBN>
		<publisher>wiley</publisher>
		<edition>3</edition>
		<price>350</price>
	</book>
	<book>
		<title>internet worldwideweb</title>
		<author>ditel&amp;ditel</author>
		<ISBN>123-456-781</ISBN>
		<publisher>person</publisher>
		<edition>3</edition>
		<price>450</price>
	</book>
</bookstore>
```
### b.   Write a Document Type Definition (DTD) or XML Schema Definition (XSD) to validate the above XML file.
#### bookstore.dtd usting dtd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ELEMENT bookstore (book+)>
<!ELEMENT book (title,author,ISBN,publisher,edition,price)>
<!ELEMENT title (#PCDATA)>
<!ELEMENT author (#PCDATA)>
<!ELEMENT ISBN (#PCDATA)>
<!ELEMENT publisher (#PCDATA)>
<!ELEMENT edition (#PCDATA)>
<!ELEMENT price (#PCDATA)>
```
#### Validation using XSD:Bookstore.xml
```xml
<bookstore xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xsi:noNamespaceSchemaLocation="C:\wt\bookstore.xsd">
	<book>
		<title>web programming</title>
		<author>chrisbates</author>
		<ISBN>123-456-789</ISBN>
		<publisher>wiley</publisher>
		<edition>3</edition>
		<price>350</price>
	</book>
	<book>
		<title>internet worldwideweb</title>
		<author>ditel&amp;ditel</author>
		<ISBN>123-456-781</ISBN>
		<publisher>person</publisher>
		<edition>3</edition>
		<price>450</price>
	</book>
</bookstore>
```
##### bookstore.xsd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema elementFormDefault="qualified" attributeFormDefault="unqualified"
	xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="bookstore">
		<xs:complexType>
			<xs:sequence>
				<xs:element name="book" maxOccurs="unbounded">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="title" type="xs:string"></xs:element>
							<xs:element name="author" type="xs:string"></xs:element>
							<xs:element name="ISBN" type="xs:string"></xs:element>
							<xs:element name="publisher" type="xs:string"></xs:element>
							<xs:element name="edition" type="xs:int"></xs:element>
							<xs:element name="price" type="xs:decimal"></xs:element>
						</xs:sequence>
					</xs:complexType>
				</xs:sequence>
			</xs:complexType>
		</xs:element>
	</xs:schema>
```
---
## SET-4
### a. Prepare a JSON file with Student information and display the content in HTML Table format.
```html
<!DOCTYPE html>
<html>
<head>
    <style>
        table{
        border-collapse: collapse;
        }
        th,td{
        border: 1px solid black;
        padding: 8px;
        text-align: center;
        }
        th{
        background-color: black;
        color: white;
        }
    </style>
</head>
<body>
    <center>
        <h1> How to populate Json data into table</h1>
        <h2> Json- Javascript</h2>
        <hr />
        <table id="mytable">
            <thead>
                <tr>
                    <th>name</th>
                    <th>email</th>
                    <th>age</th>
                </tr>
            </thead>
            <tbody></tbody>
    </center>
</body>
<script>
    const jsonData=[
    {
    "name":  "charan",
    "email":"charan@gmail.com",
    "age":30
    },
    {
    "name":  "Roy",
    "email":"roy@gmail.com",
    "age":35
    },
    {
    "name":  "sam",
    "email":"sam@gmail.com",
    "age":40
    }
    ];
    const tableBody=document.querySelector("#mytable tbody");
    jsonData.forEach(person =>{
    const row=document.createElement('tr');
    const nameCell=document.createElement('td');
    nameCell.textContent=person.name;
    row.appendChild(nameCell);
    const emailCell=document.createElement('td');
    emailCell.textContent=person.email;
    row.appendChild(emailCell);
    const ageCell=document.createElement('td');
    ageCell.textContent=person.age;
    row.appendChild(ageCell);
    tableBody.appendChild(row);
    });
</script>
</html>
```

## b. Create a static web page which displays your personal details.
```html
<!DOCTYPE html>
<html>
<head>
  <title>Personal Info</title>
  <style>
    body, h1, p { margin: 0; padding: 0; }
    .section {
      height: 400px; display: flex; justify-content: center; align-items: center;
      color: black; margin: auto; max-width: 80%; 
    }
    .firstsection { background: green; }
    .secondsection { background: blue; }
    .text-big { font-size: 35px; font-weight: bold; }
    .text-small { font-size: 18px; }
  </style>
</head>
<body>
  <section class="section firstsection">
    <div>
      <h1 class="text-big">Personal Information</h1>
      <p class="text-small">Name: Xina <br> Roll No: 21311A6669 <br> SECTION: Nach</p>
    </div>
  </section>
  <section class="section secondsection">
    <div>
      <h1 class="text-big">Contact Details</h1>
      <p class="text-small">E-Mail: meow@beluga.ru <br> Mobile: 1234321234</p>
    </div>
  </section>
</body>
</html>
```
---
## SET-5
###  a. Create servlet program to display ‘HELLO WORLD’ message using tomcat server.
Steps to execute servlet program:
1. Open XAMPP Control Panel and start the Apache Tomcat service
2. In the XAMPP Tomcat directory, navigate to the “Webapps” folder
3. Create a new folder to host the servlet application “helloworld”
4. In the new folder, create a “WEB-INF” folder
5. In the “WEB-INF” folder, create a file “web.xml” with the following contents:
   
```xml
<web-app>
    <servlet>
        <servlet-name>XYZ</servlet-name>
        <servlet-class>Test</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>XYZ</servlet-name>
        <url-pattern>/demo</url-pattern>
    </servlet-mapping>
</web-app>
```
6. Create a new folder called “classes” within the “WEB-INF” folder
7. In the classes folder, create a file “Test.java” with the following contents:
```java
import javax.servlet.*;
import java.io.*;
public class Test extends GenericServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws IOException, ServletException {
        PrintWriter o = res.getWriter();
        o.print("Hello World");
    }
}
```
8. Save the file and compile it using the following command:
javac -classpath “C:\xampp\tomcat\lib\servlet-api.jar” Test.java
9. Open the browser and navigate to the url “localhost:8080/helloworld/demo” to view the
output.
### b. Write PHP program to establish database connection and to create below database and table.New Database name: DB_SNIST New Table name: TABLE_SNIST
#### DataBase Table Creation
```php
<?php
$servername = "localhost"'
$username = "root";
$password = "";
$database = "dbsam";
$conn = mysqli_connect($servername,$username,$password,$database);
echo "connection was successfull";
$sql = "create table 'table name' ('sno' int (5), 'name' varchar(12), primary key ('sno'))";
?>
```
#### DataBase Creation
```php
<?php
$servername = "localhost"'
$username = "root";
$password = "";
$conn = mysqli_connect($servername,$username,$password);
$sql = "CREATE DATABASE dbsam";
mysqli_query($conn,$sql);
echo "connection was successfull";
?>
```
#### DataBase Connection
```php
<?php
echo "welcome to connect to db";
$servername = "localhost"'
$username = "root";
$password = "";
$conn = mysqli_connect($servername,$username,$password);
echo "connection was successfull";
?>
```
---
## SET-6
### a.  Create angular project with name MY_First_Angular_App and write simple Angular program to display the name SNIST.
1. Create a new Angular project with the following command:
```ng new my-first-angular-app```
2. Navigate to the project directory:
cd my-first-angular-app

3. In the “app.component.html” file, add the following code:
```html
<!DOCTYPE html>
<html>
  <head>
    <title>AngularJS First App</title>
    <script src="scripts/angular.js"></script>
  </head>
  <body>
    <div ng-app="myApp">
      <h1>SNIST angular application</h1>
    </div>
  </body>
</html>
```
4. Run the Angular development server:
```ng serve```
5. Navigate to “localhost:4200” to view the output

### b.  Create a web page through which the user can enter his / her details to become an authenticated user of that page.
#### HTML File:
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Sign Up Form</title>
  <link rel="stylesheet" href="styles.css"> <!-- Link to your CSS file -->
</head>
<body>
  <form action="action_page.php" style="border:1px solid #ccc; padding: 16px;">
    <h1>Sign Up</h1>
    <p>Please fill in this form to create an account.</p>
    <hr>
    <label for="email"><b>Email</b></label>
    <input type="text" placeholder="Enter Email" name="email" required>
    
    <label for="psw"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="psw" required>
    
    <label for="psw-repeat"><b>Repeat Password</b></label>
    <input type="password" placeholder="Repeat Password" name="psw-repeat" required>
    
    <label>
      <input type="checkbox" checked="checked" name="remember"> Remember me
    </label>
    <p>By creating an account you agree to our <a href="#" style="color:dodgerblue">Terms & Privacy</a>.</p>
    
    <div class="clearfix">
      <button type="button" class="cancelbtn">Cancel</button>
      <button type="submit" class="signupbtn">Sign Up</button>
    </div>
  </form>
</body>
</html>
```
#### CSS File:
```css
* { box-sizing: border-box; }
input[type=text], input[type=password] {
  width: 100%;
  padding: 15px;
  margin: 5px 0 22px;
  border: none;
  background: #f1f1f1;
}
input:focus {
  background-color: #ddd;
  outline: none;
}
hr { border: 1px solid #f1f1f1; margin-bottom: 25px; }
button {
  width: 100%; padding: 14px 20px;
  background-color: #04AA6D; color: white;
  border: none; cursor: pointer;
  margin: 8px 0; opacity: 0.9;
}
button:hover { opacity: 1; }
.cancelbtn { background-color: #f44336; }
.cancelbtn, .signupbtn {
  width: 50%; float: left;
}
.clearfix::after { content: ""; clear: both; display: table; }
@media (max-width: 300px) {
  .cancelbtn, .signupbtn { width: 100%; }
}
```
---