from tortoise.contrib.pydantic import pydantic_model_creator

from src.database.models import Users

# pydantic_model_creator is a Tortoise helper that
# allows us to create pydantic models from Tortoise models,
# which we'll use to create and retrieve database records

# for creating new users.
UserInSchema = pydantic_model_creator(
    Users,
    name="UserIn",
    exclude_readonly=True,
)

# for retrieving user info to be used outside our application,
# for returning to end users.
UserOutSchema = pydantic_model_creator(
    Users,
    name="UserOut",
    exclude=["password", "created_at", "modified_at"],
)

# for retrieving user info to be used within our application,
# for validating users.
UserDatabaseSchema = pydantic_model_creator(
    Users,
    name="User",
    exclude=["created_at", "modified_at"],
)
