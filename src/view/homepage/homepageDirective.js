var aabrham = angular.module('aabrham', []);

aabrham.controller('HomepageController', function HomepageController($scope, $http) {
    $scope.signout = function () {
        $http.get("/homepage/api/signout").then(function (result) {
            result.data.result ?
                window.location.href = "/" :
                $scope.failedLogin = true;
        });
    }

    $scope.insertItem = function (itemName) {
        let message = {
            itemName: itemName
        };

        $http.post("/api/item/insert", JSON.stringify(message)).then(function (result) {
            if (!result.data.result) {
                $scope.errorMessage = result.data.error;
                $scope.insertError = true;
            }
        });
    }
});