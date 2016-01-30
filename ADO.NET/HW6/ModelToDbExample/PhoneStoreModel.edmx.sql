
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 10/03/2015 12:55:47
-- Generated from EDMX file: D:\dev\ShmelevHW\ADO.NET\HW6\ModelToDbExample\PhoneStoreModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [CarsDB];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK_DriversCars]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[DriversSet] DROP CONSTRAINT [FK_DriversCars];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[CarsSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[CarsSet];
GO
IF OBJECT_ID(N'[dbo].[DriversSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[DriversSet];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'CarsSet'
CREATE TABLE [dbo].[CarsSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [Speed] float  NOT NULL
);
GO

-- Creating table 'DriversSet'
CREATE TABLE [dbo].[DriversSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [Adress] nvarchar(max)  NOT NULL,
    [Cars_Id] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'CarsSet'
ALTER TABLE [dbo].[CarsSet]
ADD CONSTRAINT [PK_CarsSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'DriversSet'
ALTER TABLE [dbo].[DriversSet]
ADD CONSTRAINT [PK_DriversSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [Cars_Id] in table 'DriversSet'
ALTER TABLE [dbo].[DriversSet]
ADD CONSTRAINT [FK_DriversCars]
    FOREIGN KEY ([Cars_Id])
    REFERENCES [dbo].[CarsSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_DriversCars'
CREATE INDEX [IX_FK_DriversCars]
ON [dbo].[DriversSet]
    ([Cars_Id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------