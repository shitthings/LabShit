## Program 1
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <title>SNIST Website</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { margin: 0; font-family: sans-serif; }
    header { background: #f1f1f1; padding: 20px; text-align: center; }
    h1 { margin: 0; }
    nav { background: #333; display: flex; justify-content: space-between; padding: 10px; }
    nav a { color: #f2f2f2; text-decoration: none; padding: 10px; }
    nav a:hover { background: #ddd; color: black; }
    .content { display: flex; }
    .column { width: 33.33%; padding: 15px; }
  </style>
</head>
<body>
  <header>
    <h1>SNIST</h1>
    <p>Sreenidhi Institute of Science and Technology (Established 1997)</p>
  </header>
  <nav>
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Departmental Info</a>
  </nav>
  <div class="content">
    <div class="column">
      <h2>College Info</h2>
      <p>Sreenidhi Institute of Science and Technology, sponsored by Sree Educational Group, offers undergraduate and postgraduate programs in engineering, sciences, and management. Affiliated to Jawaharlal Nehru Technological University Hyderabad (JNTUH), the institute is known for its quality education and placements.</p>
    </div>
    <div class="column">
      <h2>Branches Info</h2>
      <p>CSE, IT, ECE, EEE, MECH, CIVIL...</p>
    </div>
    <div class="column">
      <h2>Address</h2>
      <p>GHATKESAR, YAMNAMPET, HYDERABAD</p>
    </div>
  </div>
</body>
</html>
```
## Program 2
```js
function calculate(operator, number1, number2) {
  switch (operator) {
    case '+':
      return number1 + number2;
    case '-':
      return number1 - number2;
    case '*':
      return number1 * number2;
    case '/':
      return number2 !== 0 ? number1 / number2 : "Division by zero error";
    default:
      return "Invalid operator";
  }
}
const operator = prompt('Enter operator ( +, -, *, / ): ');
const number1 = parseFloat(prompt('Enter first number: '));
const number2 = parseFloat(prompt('Enter second number: '));
const result = calculate(operator, number1, number2);
console.log(`${number1} ${operator} ${number2} = ${result}`);
```
## Program 3
```xml
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
## DataBase Table Creation
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
## DataBase Creation
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
## DataBase Connection
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
## Java thing
```java
import javax.servlet.*;
import java.io.*;
public class Test extends GenericServlet{
public void service(ServletRequest req, ServletResponse res) throws IOException, ServletException{
PrintWriter o = res.getWriter();
o.print("HELLO FROM SERVLET");
}
}
```
```xml
<web-app>
	<servlet>
		<servlet-name>AFROZ</servlet-name>
		<servlet-class>Test</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>AFROZ</servlet-name>
		<url-pattern>/Demo</url-pattern>
	</servlet-mapping>
</web-app>
```
## Angular JS
```html
<!DOCTYPE html>
<html>
<head>
  <title>AngularJS First App</title>
  <script src="scripts/angular.js"></script>
</head>
<body>
  <h1>Sample App</h1>
  <div ng-app="myApp">
    <p>Enter name: <input type="text" ng-model="name"></p>
    <p>Hello <span ng-bind="name"></span></p>
  </div>
</body>
</html>
```