public class Patient {
    private String name;
    private int age;
    private String gender;
    private String dob;
    private String phone;

    public Patient(String name, int age, String gender, String dob, String phone) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.dob = dob;
        this.phone = phone;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getGender() {
        return gender;
    }

    public String getDob() {
        return dob;
    }

    public String getPhone() {
        return phone;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public void setDob(String dob) {
        this.dob = dob;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }
}