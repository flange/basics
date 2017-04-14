import java.util.Objects;

public class Person {

  public Integer age;
  public String name;

  public Person(String name, int age) {
    this.age = age;
    this.name = name;
  }

  public boolean equals(Object o) {

    if (o == null)
      return false;

    if (o == this)
      return true;

    if (!(o instanceof Person))
      return false;

    Person other = (Person) o;

    return (Objects.equals(age, other.age)) &&
           (Objects.equals(name, other.name));
  }

  public int hashCode() {
    return Objects.hash(age, name);
  }

  public String toString() {
    return "{name: \"" + name + "\", age: " + age + "}";
  }

}
