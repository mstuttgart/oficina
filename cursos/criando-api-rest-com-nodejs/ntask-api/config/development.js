const logger = require("../logger");

module.exports = {
  db: {
    database: "ntask",
    username: "",
    password: "",
    params: {
      dialect: "sqlite",
      storage: "ntask.sqlite",
      logging: (sql) => {
        logger.info(`[${new Date()}] ${sql}`);
      },
      define: {
        underscore: true,
      },
    },
  },
  jwt: {
    secret: "Nta$K-AP1",
    option: { session: false },
  },
};
