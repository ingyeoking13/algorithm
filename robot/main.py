from typing import List
from pydantic import BaseModel


class Solver(BaseModel):
    def validate(self, source: List[List[str]], target: List[List[str]]):
        if not source or not target:
            raise RuntimeError()

    def solve(self, source: List[List[str]], target: List[List[str]]):
        rows = len(source)
        cols = len(source[0])
