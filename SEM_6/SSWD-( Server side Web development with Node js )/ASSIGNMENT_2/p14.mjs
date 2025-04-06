const calculateAverage = (marks) => {
  const total = marks.reduce((sum, mark) => sum + mark, 0);
  return total / marks.length;
};

const students = [
  {
    name: "Student 1",
    marks: [85, 90, 78, 92, 88, 76],
  },
  {
    name: "Student 2",
    marks: [80, 85, 88, 90, 84, 82],
  },
  {
    name: "Student 3",
    marks: [78, 82, 85, 88, 80, 86],
  },
];

students.forEach((student) => {
  const average = calculateAverage(student.marks);
  console.log(`${student.name} - Average Marks: ${average.toFixed(2)}`);
});
