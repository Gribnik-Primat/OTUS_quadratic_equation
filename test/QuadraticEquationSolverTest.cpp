#include "QuadraticEquationSolver.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(QuadraticEquationSolverTest, NoRoots)
{
    QuadraticEquationSolver solver;
    std::vector<double> roots = solver.solve(1, 0, 1);
    ASSERT_TRUE(roots.empty());
}

TEST(QuadraticEquationSolverTest, TwoDistinctRoots)
{
    QuadraticEquationSolver solver;
    std::vector<double> roots = solver.solve(1, 0, -1);
    ASSERT_EQ(roots.size(), 2);
    ASSERT_DOUBLE_EQ(roots[0], 1);
    ASSERT_DOUBLE_EQ(roots[1], -1);
}

TEST(QuadraticEquationSolverTest, OneRootMultiplicityTwo)
{
    QuadraticEquationSolver solver;
    std::vector<double> roots = solver.solve(1, 2, 1);
    ASSERT_EQ(roots.size(), 1);
    ASSERT_DOUBLE_EQ(roots[0], -1);
}

TEST(QuadraticEquationSolverTest, ZeroCoefficient)
{
    QuadraticEquationSolver solver;
    ASSERT_THROW(solver.solve(0, 2, 1), std::invalid_argument);
}

TEST(QuadraticEquationSolverTest, DiscriminantComparisonWithEpsilon)
{
    QuadraticEquationSolver solver;
    std::vector<double> roots = solver.solve(1, 4, 4);
    ASSERT_EQ(roots.size(), 1);
    ASSERT_NEAR(roots[0], -2.0, std::numeric_limits<double>::epsilon());
}

TEST(QuadraticEquationSolverTest, NonNumericCoefficients)
{
    QuadraticEquationSolver solver;
    ASSERT_THROW(solver.solve(std::numeric_limits<double>::quiet_NaN(), 2, 1), std::invalid_argument);
    ASSERT_THROW(solver.solve(std::numeric_limits<double>::infinity(), 2, 1), std::invalid_argument);
    ASSERT_THROW(solver.solve(1, std::numeric_limits<double>::quiet_NaN(), 1), std::invalid_argument);
    ASSERT_THROW(solver.solve(1, std::numeric_limits<double>::infinity(), 1), std::invalid_argument);
    ASSERT_THROW(solver.solve(1, 2, std::numeric_limits<double>::quiet_NaN()), std::invalid_argument);
    ASSERT_THROW(solver.solve(1, 2, std::numeric_limits<double>::infinity()), std::invalid_argument);
}
