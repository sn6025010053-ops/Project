public class Appointment {
    private String id;
    private Patient patient;
    private Schedule schedule;
    private double hours;
    private double fee;

    public Appointment(String id, Patient patient, Schedule schedule, double hours) {
        this.id = id;
        this.patient = patient;
        this.schedule = schedule;
        this.hours = hours;
        this.fee = hours * schedule.getDoctor().getHourlyRate();
    }

    // Getters
    public String getId() {
        return id;
    }

    public Patient getPatient() {
        return patient;
    }

    public Schedule getSchedule() {
        return schedule;
    }

    public double getHours() {
        return hours;
    }

    public double getFee() {
        return fee;
    }

    // Setters
    public void setId(String id) {
        this.id = id;
    }

    public void setPatient(Patient patient) {
        this.patient = patient;
    }

    public void setSchedule(Schedule schedule) {
        this.schedule = schedule;
    }

    public void setHours(double hours) {
        this.hours = hours;
        this.fee = hours * schedule.getDoctor().getHourlyRate();
    }

    public void setFee(double fee) {
        this.fee = fee;
    }


    public void display(String meetingTime) {

        System.out.println("\n===== RECEIPT =====");

        System.out.println("Patient: " + patient.getName());
        System.out.println("Age: " + patient.getAge());
        System.out.println("Gender: " + patient.getGender());
        System.out.println("DOB: " + patient.getDob());
        System.out.println("Phone: " + patient.getPhone());

        System.out.println("\nDoctor: " + schedule.getDoctor().getName());
        System.out.println("Specialist: " + schedule.getDoctor().getSpecialist());

        System.out.println("\nDay: " + schedule.getDay());
        System.out.println("Time Slot: " + schedule.getTimeSlot());
        System.out.println("Meeting Time: " + meetingTime);
        System.out.println("Room: " + schedule.getRoom());

        System.out.println("\nHours: " + hours);
        System.out.println("Total Fee: $" + fee);
    }
}