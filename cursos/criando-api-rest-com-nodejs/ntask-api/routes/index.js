module.exports = (app) => {
  app.get("/", (req, res) => {
    res.json({ status: "NTask API" });
  });
};

module.exports = (app) => {
  const Tasks = app.models.tasks;

  app.get("/tasks", (req, res) => {
    Tasks.findAll({}, (tasks) => {
      res.json({ tasks });
    });
  });
};
