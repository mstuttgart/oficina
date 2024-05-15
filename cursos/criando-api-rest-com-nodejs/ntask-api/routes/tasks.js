module.exports = (app) => {
  const Tasks = app.models.tasks;

  app.get("/tasks", async (req, res) => {
    try {
      const tasks = await Tasks.findAll();
      res.json({ tasks });
    } catch (err) {
      res.status(500).json(err);
    }
  });
};
