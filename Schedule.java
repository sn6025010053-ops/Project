public class Schedule {
    private Doctor doctor;
    private String day;
    private String timeSlot;
    private String room;

    public Schedule(Doctor doctor, String day, String timeSlot, String room) {
        this.doctor = doctor;
        this.day = day;
        this.timeSlot = timeSlot;
        this.room = room;
    }

    // Getters
    public Doctor getDoctor() {
        return doctor;
    }

    public String getDay() {
        return day;
    }

    public String getTimeSlot() {
        return timeSlot;
    }

    public String getRoom() {
        return room;
    }

    // Setters
    public void setDoctor(Doctor doctor) {
        this.doctor = doctor;
    }

    public void setDay(String day) {
        this.day = day;
    }

    public void setTimeSlot(String timeSlot) {
        this.timeSlot = timeSlot;
    }

    public void setRoom(String room) {
        this.room = room;
    }
}