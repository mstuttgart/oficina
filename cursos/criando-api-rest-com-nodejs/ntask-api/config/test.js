module.exports = {
  db: {
    database: "ntask_test",
    username: "",
    password: "",
    parmas: {
      dialect: "sqlite",
      storage: "ntask_test.sqlite",
      logging: false,
      define: {
        underscored: true,
      },
    },
  },
  jwt: {
    secret: "Nta$K-AP1",
    options: { session: false },
  },
};
