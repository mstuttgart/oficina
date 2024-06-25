from typing import Optional

from pydantic import BaseModel


# ensuring the username from the token is a string.
class TokenData(BaseModel):
    username: Optional[str] = None


# for sending status messages back to the end user
class Status(BaseModel):
    message: str
