#include <gtest/gtest.h>
#include "Geometry.h"

class GeometryFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    GeometryFixture() : Test() {
        Point *points[] = {new Point(0, 10), new Point(-10, 0), new Point(-10, 0), new Point(10, 0)};
        geometry = new Geometry(points, 4);
    }

    virtual  ~GeometryFixture() {
        delete geometry;
    }

    Geometry *geometry;

};

TEST_F(GeometryFixture, setGeometry) {
    Geometry dummy = *geometry;
    dummy.printDistance();
    dummy.printDirectMeets();
}

TEST_F(GeometryFixture, addPoints) {
    Geometry dummy = *geometry;
    Geometry compareTarget = Geometry();
    compareTarget.addPoint(Point(1,0));
    compareTarget.addPoint(Point(0,1));
    EXPECT_EQ(compareTarget.getPointCounts(), 2);
    EXPECT_NE(compareTarget.getPointCounts(),dummy.getPointCounts());
}

TEST_F(GeometryFixture, printDistances) {
    Geometry dummy = *geometry;
    dummy.printDistance();
}

TEST_F(GeometryFixture, printDirectMeets) {
    Geometry dummy = *geometry;
    dummy.printDirectMeets();
}

TEST_F(GeometryFixture, asdf) {
    Geometry dummy = *geometry;
}