import java.util.Objects;

public class Student extends Person {

  public Integer id;

  public Student(String name, Integer age, Integer id) {
    super(name, age);

    this.id = id;
  }

  public boolean equals(Object o) {

    if (o == null)
      return false;

    if (o == this)
      return true;

    if (!(o instanceof Student))
      return false;

    Student other = (Student) o;

    return (super.equals(o)) &&
           (Objects.equals(id, other.id));
  }

  public int hashCode() {
    return Objects.hash(name, age, id);
  }

  public String toString() {
    return "{name: \"" + name + "\", age: " + age + ", id: " + id + "}";
  }

}
